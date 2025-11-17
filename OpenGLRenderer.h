#pragma once

#include "PLYLoader.h"
#include <Windows.h>

enum class ProjectionMode {
    ORTHOGRAPHIC,
    PERSPECTIVE
};

class OpenGLRenderer {
public:
    OpenGLRenderer();
    ~OpenGLRenderer();

    bool Initialize(HWND hWnd);
    void Cleanup();
    void Render();
    void Resize(int width, int height);

    void LoadPLY1(const std::string& filename);
    void LoadPLY2(const std::string& filename);
    void SetProjectionMode(ProjectionMode mode);

    // Camera controls
    void RotateCamera(float deltaX, float deltaY);
    void ZoomCamera(float delta);

private:
    HWND m_hWnd;
    HDC m_hDC;
    HGLRC m_hRC;

    PLYLoader m_plyLoader1;
    PLYLoader m_plyLoader2;
    
    bool m_hasPLY1;
    bool m_hasPLY2;

    ProjectionMode m_projectionMode;
    
    int m_width;
    int m_height;

    // Camera parameters
    float m_rotationX;
    float m_rotationY;
    float m_zoom;

    void SetupProjection();
    void RenderPLY(const PLYLoader& loader, float offsetX);
    void CalculateSceneCenter();

    float m_sceneCenterX, m_sceneCenterY, m_sceneCenterZ;
    float m_sceneRadius;
};
