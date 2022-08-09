#include "Model.h"
#include "../Core/File.h"
#include <sstream>
#include <iostream>

namespace towr {
	Model::Model(const std::string filename){
		Load(filename);
		m_radius = CaluclateRadius();
	}

	void Model::Draw(Renderer& renderer, const Vector2 position, float angle, const Vector2& scale){
		/*towr::Color color;
		color.r = towr::random(256);
		color.g = towr::random(256);
		color.b = towr::random(256);
		color.r = 256;*/

		//draw model
		for (int i = 0; i < m_points.size() - 1; i++) {
			towr::Vector2 p1 = Vector2::Rotate((m_points[i] * scale), angle) + position;
			towr::Vector2 p2 = Vector2::Rotate((m_points[i + 1] * scale), angle) + position;

			renderer.DrawLine(p1, p2, m_color);
		}
	}

	void Model::Load(const std::string& filename){
		std::string buffer;

		towr::ReadFile(filename, buffer);

		//read color
		std::istringstream stream(buffer);
		stream >> m_color;
		//m_color = { 255,255,255,255 };

		//read number of points
		std::string line;
		std::getline(stream, line);
		size_t numPoints = std::stoi(line);

		// read model points
		for (size_t i = 0; i < numPoints; i++) {
			Vector2 point;

			stream >> point;
			m_points.push_back(point);
		}
	}

	float Model::CaluclateRadius(){
		float radius = 0;

		//find the largest length (radius)
		for (auto& point : m_points) {
			if (point.Length() > radius) radius = point.Length();
		}

		return radius;
	}

}
