#include "pch.h"
#include "OpenGLRenderer.h"
#include <cmath>

OpenGLRenderer::OpenGLRenderer()
    : m_hWnd(nullptr)
    , m_hDC(nullptr)
    , m_hRC(nullptr)
    , m_hasPLY1(false)
    , m_hasPLY2(false)
    , m_projectionMode(ProjectionMode::PERSPECTIVE)
    , m_width(800)
    , m_height(600)
    , m_rotationX(30.0f)
    , m_rotationY(45.0f)
    , m_zoom(5.0f)
    , m_sceneCenterX(0.0f)
    , m_sceneCenterY(0.0f)
    , m_sceneCenterZ(0.0f)
    , m_sceneRadius(1.0f) {
}

OpenGLRenderer::~OpenGLRenderer() {
    Cleanup();
}

bool OpenGLRenderer::Initialize(HWND hWnd) {
    m_hWnd = hWnd;
    m_hDC = ::GetDC(hWnd);

    if (!m_hDC) {
        return false;
    }

    PIXELFORMATDESCRIPTOR pfd = {
        sizeof(PIXELFORMATDESCRIPTOR),
        1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
        PFD_TYPE_RGBA,
        32,
        0, 0, 0, 0, 0, 0,
        0,
        0,
        0,
        0, 0, 0, 0,
        24,
        8,
        0,
        PFD_MAIN_PLANE,
        0,
        0, 0, 0
    };

    int pixelFormat = ChoosePixelFormat(m_hDC, &pfd);
    if (!pixelFormat) {
        return false;
    }

    if (!SetPixelFormat(m_hDC, pixelFormat, &pfd)) {
        return false;
    }

    m_hRC = wglCreateContext(m_hDC);
    if (!m_hRC) {
        return false;
    }

    if (!wglMakeCurrent(m_hDC, m_hRC)) {
        return false;
    }

    // Initialize OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

    GLfloat lightPos[] = { 1.0f, 1.0f, 1.0f, 0.0f };
    GLfloat lightAmbient[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    GLfloat lightDiffuse[] = { 0.7f, 0.7f, 0.7f, 1.0f };

    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);

    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

    return true;
}

void OpenGLRenderer::Cleanup() {
    if (m_hRC) {
        wglMakeCurrent(nullptr, nullptr);
        wglDeleteContext(m_hRC);
        m_hRC = nullptr;
    }

    if (m_hDC && m_hWnd) {
        ::ReleaseDC(m_hWnd, m_hDC);
        m_hDC = nullptr;
    }
}

void OpenGLRenderer::Resize(int width, int height) {
    m_width = width;
    m_height = height;

    if (height == 0) {
        height = 1;
    }

    glViewport(0, 0, width, height);
}

void OpenGLRenderer::SetupProjection() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspect = static_cast<float>(m_width) / static_cast<float>(m_height);

    if (m_projectionMode == ProjectionMode::PERSPECTIVE) {
        gluPerspective(45.0, aspect, 0.1, 1000.0);
    } else {
        float size = m_sceneRadius * 1.5f;
        if (aspect >= 1.0f) {
            glOrtho(-size * aspect, size * aspect, -size, size, 0.1, 1000.0);
        } else {
            glOrtho(-size, size, -size / aspect, size / aspect, 0.1, 1000.0);
        }
    }

    glMatrixMode(GL_MODELVIEW);
}

void OpenGLRenderer::Render() {
    if (!m_hDC || !m_hRC) {
        return;
    }

    wglMakeCurrent(m_hDC, m_hRC);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    SetupProjection();

    glLoadIdentity();

    // Set up camera
    gluLookAt(0.0, 0.0, m_zoom * m_sceneRadius,
              m_sceneCenterX, m_sceneCenterY, m_sceneCenterZ,
              0.0, 1.0, 0.0);

    // Apply rotations
    glRotatef(m_rotationX, 1.0f, 0.0f, 0.0f);
    glRotatef(m_rotationY, 0.0f, 1.0f, 0.0f);

    // Translate to center
    glTranslatef(-m_sceneCenterX, -m_sceneCenterY, -m_sceneCenterZ);

    // Render both PLY files side by side if both are loaded
    if (m_hasPLY1 && m_hasPLY2) {
        float offset = m_sceneRadius * 0.6f;
        RenderPLY(m_plyLoader1, -offset);
        RenderPLY(m_plyLoader2, offset);
    } else if (m_hasPLY1) {
        RenderPLY(m_plyLoader1, 0.0f);
    } else if (m_hasPLY2) {
        RenderPLY(m_plyLoader2, 0.0f);
    }

    SwapBuffers(m_hDC);
}

void OpenGLRenderer::RenderPLY(const PLYLoader& loader, float offsetX) {
    const auto& vertices = loader.GetVertices();
    const auto& faces = loader.GetFaces();

    if (vertices.empty() || faces.empty()) {
        return;
    }

    glPushMatrix();
    glTranslatef(offsetX, 0.0f, 0.0f);

    glBegin(GL_TRIANGLES);
    for (const auto& face : faces) {
        if (face.indices.size() >= 3) {
            // Render as triangles (triangulate if needed)
            for (size_t i = 1; i < face.indices.size() - 1; ++i) {
                int idx0 = face.indices[0];
                int idx1 = face.indices[i];
                int idx2 = face.indices[i + 1];

                if (idx0 < vertices.size() && idx1 < vertices.size() && idx2 < vertices.size()) {
                    const Vertex& v0 = vertices[idx0];
                    const Vertex& v1 = vertices[idx1];
                    const Vertex& v2 = vertices[idx2];

                    glColor3ub(v0.r, v0.g, v0.b);
                    glNormal3f(v0.nx, v0.ny, v0.nz);
                    glVertex3f(v0.x, v0.y, v0.z);

                    glColor3ub(v1.r, v1.g, v1.b);
                    glNormal3f(v1.nx, v1.ny, v1.nz);
                    glVertex3f(v1.x, v1.y, v1.z);

                    glColor3ub(v2.r, v2.g, v2.b);
                    glNormal3f(v2.nx, v2.ny, v2.nz);
                    glVertex3f(v2.x, v2.y, v2.z);
                }
            }
        }
    }
    glEnd();

    glPopMatrix();
}

void OpenGLRenderer::LoadPLY1(const std::string& filename) {
    m_hasPLY1 = m_plyLoader1.LoadPLY(filename);
    if (m_hasPLY1) {
        CalculateSceneCenter();
    }
}

void OpenGLRenderer::LoadPLY2(const std::string& filename) {
    m_hasPLY2 = m_plyLoader2.LoadPLY(filename);
    if (m_hasPLY2) {
        CalculateSceneCenter();
    }
}

void OpenGLRenderer::CalculateSceneCenter() {
    float minX = 0.0f, minY = 0.0f, minZ = 0.0f;
    float maxX = 0.0f, maxY = 0.0f, maxZ = 0.0f;

    bool hasData = false;

    if (m_hasPLY1) {
        m_plyLoader1.GetBoundingBox(minX, minY, minZ, maxX, maxY, maxZ);
        hasData = true;
    }

    if (m_hasPLY2) {
        float minX2, minY2, minZ2, maxX2, maxY2, maxZ2;
        m_plyLoader2.GetBoundingBox(minX2, minY2, minZ2, maxX2, maxY2, maxZ2);
        
        if (hasData) {
            minX = std::min(minX, minX2);
            minY = std::min(minY, minY2);
            minZ = std::min(minZ, minZ2);
            maxX = std::max(maxX, maxX2);
            maxY = std::max(maxY, maxY2);
            maxZ = std::max(maxZ, maxZ2);
        } else {
            minX = minX2;
            minY = minY2;
            minZ = minZ2;
            maxX = maxX2;
            maxY = maxY2;
            maxZ = maxZ2;
        }
    }

    if (hasData) {
        m_sceneCenterX = (minX + maxX) / 2.0f;
        m_sceneCenterY = (minY + maxY) / 2.0f;
        m_sceneCenterZ = (minZ + maxZ) / 2.0f;

        float dx = maxX - minX;
        float dy = maxY - minY;
        float dz = maxZ - minZ;
        m_sceneRadius = std::sqrt(dx * dx + dy * dy + dz * dz) / 2.0f;

        if (m_sceneRadius < 0.1f) {
            m_sceneRadius = 1.0f;
        }
    }
}

void OpenGLRenderer::SetProjectionMode(ProjectionMode mode) {
    m_projectionMode = mode;
}

void OpenGLRenderer::RotateCamera(float deltaX, float deltaY) {
    m_rotationY += deltaX;
    m_rotationX += deltaY;

    // Clamp rotation X to avoid gimbal lock
    if (m_rotationX > 89.0f) m_rotationX = 89.0f;
    if (m_rotationX < -89.0f) m_rotationX = -89.0f;
}

void OpenGLRenderer::ZoomCamera(float delta) {
    m_zoom -= delta * 0.1f;
    if (m_zoom < 1.0f) m_zoom = 1.0f;
    if (m_zoom > 20.0f) m_zoom = 20.0f;
}
