#include "pch.h"
#include "PLYLoader.h"
#include <fstream>
#include <sstream>
#include <algorithm>

PLYLoader::PLYLoader() {
}

PLYLoader::~PLYLoader() {
}

void PLYLoader::Clear() {
    vertices.clear();
    faces.clear();
}

bool PLYLoader::LoadPLY(const std::string& filename) {
    Clear();

    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        return false;
    }

    int vertexCount = 0;
    int faceCount = 0;
    bool hasNormals = false;
    bool hasColors = false;

    if (!ParseHeader(file, vertexCount, faceCount, hasNormals, hasColors)) {
        return false;
    }

    if (!ReadVertices(file, vertexCount, hasNormals, hasColors)) {
        return false;
    }

    if (!ReadFaces(file, faceCount)) {
        return false;
    }

    return true;
}

bool PLYLoader::ParseHeader(std::ifstream& file, int& vertexCount, int& faceCount,
                            bool& hasNormals, bool& hasColors) {
    std::string line;
    std::getline(file, line);
    
    if (line.find("ply") == std::string::npos) {
        return false;
    }

    bool inHeader = true;
    while (inHeader && std::getline(file, line)) {
        std::istringstream iss(line);
        std::string word;
        iss >> word;

        if (word == "element") {
            std::string type;
            int count;
            iss >> type >> count;
            if (type == "vertex") {
                vertexCount = count;
            } else if (type == "face") {
                faceCount = count;
            }
        } else if (word == "property") {
            if (line.find("nx") != std::string::npos || 
                line.find("ny") != std::string::npos || 
                line.find("nz") != std::string::npos) {
                hasNormals = true;
            }
            if (line.find("red") != std::string::npos || 
                line.find("green") != std::string::npos || 
                line.find("blue") != std::string::npos) {
                hasColors = true;
            }
        } else if (word == "end_header") {
            inHeader = false;
        }
    }

    return true;
}

bool PLYLoader::ReadVertices(std::ifstream& file, int count, bool hasNormals, bool hasColors) {
    vertices.reserve(count);

    for (int i = 0; i < count; ++i) {
        std::string line;
        if (!std::getline(file, line)) {
            return false;
        }

        std::istringstream iss(line);
        Vertex v;
        v.nx = v.ny = v.nz = 0.0f;
        v.r = v.g = v.b = 128;

        iss >> v.x >> v.y >> v.z;

        if (hasNormals) {
            iss >> v.nx >> v.ny >> v.nz;
        }

        if (hasColors) {
            int r, g, b;
            iss >> r >> g >> b;
            v.r = static_cast<unsigned char>(r);
            v.g = static_cast<unsigned char>(g);
            v.b = static_cast<unsigned char>(b);
        }

        vertices.push_back(v);
    }

    return true;
}

bool PLYLoader::ReadFaces(std::ifstream& file, int count) {
    faces.reserve(count);

    for (int i = 0; i < count; ++i) {
        std::string line;
        if (!std::getline(file, line)) {
            return false;
        }

        std::istringstream iss(line);
        Face f;
        int vertexCount;
        iss >> vertexCount;

        f.indices.resize(vertexCount);
        for (int j = 0; j < vertexCount; ++j) {
            iss >> f.indices[j];
        }

        faces.push_back(f);
    }

    return true;
}

void PLYLoader::GetBoundingBox(float& minX, float& minY, float& minZ,
                              float& maxX, float& maxY, float& maxZ) const {
    if (vertices.empty()) {
        minX = minY = minZ = maxX = maxY = maxZ = 0.0f;
        return;
    }

    minX = maxX = vertices[0].x;
    minY = maxY = vertices[0].y;
    minZ = maxZ = vertices[0].z;

    for (const auto& v : vertices) {
        minX = std::min(minX, v.x);
        minY = std::min(minY, v.y);
        minZ = std::min(minZ, v.z);
        maxX = std::max(maxX, v.x);
        maxY = std::max(maxY, v.y);
        maxZ = std::max(maxZ, v.z);
    }
}
