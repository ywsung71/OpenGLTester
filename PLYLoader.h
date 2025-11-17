#pragma once

#include <vector>
#include <string>

struct Vertex {
    float x, y, z;
    float nx, ny, nz;  // normals
    unsigned char r, g, b;  // color
};

struct Face {
    std::vector<int> indices;
};

class PLYLoader {
public:
    PLYLoader();
    ~PLYLoader();

    bool LoadPLY(const std::string& filename);
    const std::vector<Vertex>& GetVertices() const { return vertices; }
    const std::vector<Face>& GetFaces() const { return faces; }
    void Clear();

    // Bounding box for centering
    void GetBoundingBox(float& minX, float& minY, float& minZ,
                       float& maxX, float& maxY, float& maxZ) const;

private:
    std::vector<Vertex> vertices;
    std::vector<Face> faces;

    bool ParseHeader(std::ifstream& file, int& vertexCount, int& faceCount,
                    bool& hasNormals, bool& hasColors);
    bool ReadVertices(std::ifstream& file, int count, bool hasNormals, bool hasColors);
    bool ReadFaces(std::ifstream& file, int count);
};
