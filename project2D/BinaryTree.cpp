#include "BinaryTree.h"
BinaryTree::BinaryTree()
{
	m_pRoot = nullptr;
}

BinaryTree::~BinaryTree()
{
}

bool BinaryTree::isEmpty() const
{
	if (m_pRoot == nullptr)
		return true;

	else
	{
		return false;
	}
}

void BinaryTree::insert(int a_nValue)
{
	TreeNode* thisNode = m_pRoot;

	TreeNode* firstNode = m_pRoot;

	if (isEmpty() == true)

	{
		TreeNode* first = new TreeNode(a_nValue);

		m_pRoot = first;
		return;

	}



	while (thisNode != nullptr)
	{
		if (a_nValue < thisNode->getData())
		{
			TreeNode* newNode = new TreeNode(a_nValue);

			firstNode = thisNode;
			thisNode = thisNode->getLeft();

			continue;
		}

		if (a_nValue > thisNode->getData())
		{
			TreeNode* newNode = new TreeNode(a_nValue);

			firstNode = thisNode;
			thisNode = thisNode->getRight();

			continue;
		}

		if (a_nValue == thisNode->getData())

		{
			return;
		}

	}

	if (a_nValue < firstNode->getData())

	{
		TreeNode* test = new TreeNode(a_nValue);

		firstNode->setLeft(test);
	}

	if (a_nValue > firstNode->getData())

	{
		TreeNode* test = new TreeNode(a_nValue);
		firstNode->setRight(test);
	}
}

void BinaryTree::remove(int a_nValue)
{
	TreeNode* thisNode = m_pRoot;

	TreeNode* firstNode = m_pRoot;

	TreeNode** ptrthisNode = &thisNode;

	TreeNode** ptrfirstNode = &firstNode;

	if (findNode(a_nValue, ptrthisNode, ptrfirstNode))
	{

		if (thisNode->hasRight())

		{
			TreeNode* IterCurrent = (*ptrthisNode);

			TreeNode* IterParent = (*ptrfirstNode);

			if (IterCurrent->hasRight())

			{

				IterParent = IterCurrent;

				IterCurrent = IterCurrent->getRight();

			}

			while (IterCurrent->hasLeft())

			{
				IterParent = IterCurrent;

				IterCurrent = IterCurrent->getLeft();

			}

			thisNode->setData(IterCurrent->getData());

			if (IterParent->getLeft() == IterCurrent)
			{

				IterParent->setLeft(IterCurrent->getRight());
			}

			else if (IterParent->getRight() == IterCurrent)
			{
				IterParent->setRight(IterCurrent->getRight());
			}

			delete IterCurrent;
		}



		else
		{
			if (firstNode->getLeft() == thisNode)

			{
				firstNode->setLeft(thisNode->getLeft());

			}

			else if (firstNode->getRight() == thisNode)

			{
				firstNode->setRight(thisNode->getLeft());
			}

			else if (m_pRoot == thisNode)
			{
				m_pRoot = thisNode->getLeft();

			}
			delete thisNode;

		}
	}
}

TreeNode * BinaryTree::find(int a_nValue)
{
	TreeNode* thisNode = m_pRoot;

	while (thisNode != nullptr)
	{
		if (a_nValue < thisNode->getData())
		{

			thisNode = thisNode->getLeft();
			continue;

		}

		if (a_nValue > thisNode->getData())
		{
			thisNode = thisNode->getRight();

			continue;
		}

		if (a_nValue == thisNode->getData())

		{
			return thisNode;
		}
	}
}

void BinaryTree::draw(aie::Renderer2D * renderer, aie::Font* g_systemFont, TreeNode * selected)
{
	draw(renderer, m_pRoot, 640, 680, 640, g_systemFont, selected);
}

bool BinaryTree::findNode(int a_nSearchValue, TreeNode ** ppOutNode, TreeNode ** ppOutParent)
{
	TreeNode* thisnode = m_pRoot;
	TreeNode* firstnode = m_pRoot;

	while (thisnode != nullptr)

	{
		if (a_nSearchValue == thisnode->getData())

		{
			*ppOutNode = thisnode;
			*ppOutParent = firstnode;

			return true;
		}

		if (a_nSearchValue < thisnode->getData())

		{
			firstnode = thisnode;
			thisnode = thisnode->getLeft();
		}

		if (a_nSearchValue > thisnode->getData())

		{
			firstnode = thisnode;
			thisnode = thisnode->getRight();
		}
	}
	return false;
}

void BinaryTree::draw(aie::Renderer2D * renderer, TreeNode *pNode, int x, int y, int horizontalSpacing, aie::Font* g_systemFont, TreeNode * selected)
{

	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->hasLeft())
		{
			renderer->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x - horizontalSpacing, y - 80);
			draw(renderer, pNode->getLeft(), x - horizontalSpacing, y - 80, horizontalSpacing, g_systemFont, selected);
		}

		if (pNode->hasRight())
		{
			renderer->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x + horizontalSpacing, y - 80);
			draw(renderer, pNode->getRight(), x + horizontalSpacing, y - 80, horizontalSpacing, g_systemFont, selected);
		}
		pNode->draw(renderer, x, y, g_systemFont, (selected == pNode));
	}
}