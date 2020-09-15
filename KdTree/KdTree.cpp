#include "Bridges.h"
#include "KdTreeElement.h"

using namespace bridges;

KdTreeElement<int, int>* root;

bool isEmpty() {
	return root == NULL;
}

void styleKdTree(KdTreeElement<int, int>* node, int count) {
	//set nodes by dims
	if (count == 0) {
		node->setColor("azure");
	}
	else {
		node->setColor("limegreen");
	}

	//label nodes
	if (count == 0) {
		node->setLabel("X");
	}
	else {
		node->setLabel("Y");
	}
}

void insertKdTree(KdTreeElement<int, int>* subroot, KdTreeElement<int, int>* n) {
	if (n->getKey() < subroot->getKey()) {
		//goes left
		if (subroot->getLeft() == NULL) {
			subroot->setLeft(n);
			styleKdTree(n, n->getDimension());
			subroot->getLinkVisualizer(n)->setColor("turquoise");
		}
		else
			insertKdTree(subroot->getLeft(), n);
	}
	else { //goes right
		if (subroot->getRight() == NULL) {
			subroot->setRight(n);
			styleKdTree(n, n->getDimension());
			subroot->getLinkVisualizer(n)->setColor("blue");
		}
		else
			insertKdTree(subroot->getRight(), n);
	}
}

void insertKdTree(int value, int count) {
	if (isEmpty()) {
		root = new KdTreeElement<int, int>(value, count);
		styleKdTree(root, count);
	}
	else {
		insertKdTree(root, new KdTreeElement<int, int>(value, count));
	}
}


int main(int argc, char** argv) {
	// create bridges object
	Bridges bridges(6, "ambersibel",
		"59807219965");
	bridges.setTitle("A Kd Tree Example");
	bridges.setDescription("A three-level tree with partitioners cycling between X and Y. The root node color is set to red while the leaf nodes that represent code letters are set to orange.");

	// create nodes
	KdTreeElement<int, int>* t0 = new KdTreeElement<int, int>(50, 0);
	KdTreeElement<int, int>* t1 = new KdTreeElement<int, int>(25, 1);
	KdTreeElement<int, int>* t2 = new KdTreeElement<int, int>(75, 1);
	KdTreeElement<int, int>* t3 = new KdTreeElement<int, int>(20, 0);
	KdTreeElement<int, int>* t4 = new KdTreeElement<int, int>(30, 0);
	KdTreeElement<int, int>* t5 = new KdTreeElement<int, int>(60, 0);
	KdTreeElement<int, int>* t6 = new KdTreeElement<int, int>(80, 0);

	// form the links
	t0->setLeft(t1);
	t0->setRight(t2);
	t1->setLeft(t3);
	t1->setLabel("X");
	t1->setRight(t4);
	t2->setLeft(t5);
	t2->setRight(t6);

	// set partitioning dimension
	t0->setLabel("X");
	t1->setLabel("Y");
	t2->setLabel("Y");
	t3->setLabel("X");
	t4->setLabel("X");
	t5->setLabel("X");
	t6->setLabel("X");

	// set visual attributes
	t0->setColor("red");

	// color the leaf nodes that represent the code letters
	t1->setColor("orange");
	t4->setColor("orange");
	t5->setColor("orange");
	t6->setColor("orange");

	// provide BRIDGES the  handle to the tree structure and visualize
	bridges.setDataStructure(t0);
	bridges.visualize();

	//added code
	insertKdTree(50, 0);
	insertKdTree(25, 1);
	insertKdTree(20, 0);
	insertKdTree(30, 0);
	insertKdTree(75, 1);
	insertKdTree(60, 0);
	insertKdTree(80, 0);

	bridges.setDataStructure(root);
	bridges.visualize();

	return 0;
}