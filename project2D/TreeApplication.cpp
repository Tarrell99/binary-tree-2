#include "TreeApplication.h"

aie::Font* g_systemFont = nullptr;

TreeApplication::TreeApplication()
{
}

TreeApplication::~TreeApplication()
{
}

bool TreeApplication::startup()
{
	m_2dRenderer = new aie::Renderer2D();
	g_systemFont = new aie::Font("./front/consolas.ttf", 32);
	return true;
}

void TreeApplication::shutdown()
{
	delete g_systemFont;

	delete m_2dRenderer;
}

void TreeApplication::update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	static int value = 0;
	ImGui::InputInt("Value", &value);

	if (ImGui::Button("Insert", ImVec2(50, 0)))
	{
		m_binaryTree.insert(value);
		m_selectedNode = m_binaryTree.find(value);
	}
	if (ImGui::Button("Remove", ImVec2(50, 0)))
	{
		m_binaryTree.remove(value);
	}
	if (ImGui::Button("Find", ImVec2(50, 0)))
	{
		m_selectedNode = m_binaryTree.find(value);
	}
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void TreeApplication::draw()
{
	clearScreen();

	m_2dRenderer->begin();

	m_binaryTree.draw(m_2dRenderer, g_systemFont, m_selectedNode);

	m_2dRenderer->drawText(g_systemFont, "Press ESC to quit", 0, 0 + 1);

	m_2dRenderer->end();
}
