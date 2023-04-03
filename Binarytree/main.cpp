#include <iostream>
#include <ctime>
#define NEXTLN cout<<endl

using namespace std;
class Tree
{
protected:
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;

	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr)
			:Data(Data), pLeft(pLeft), pRight(pRight)
		{
			cout << "EConst:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDConst:\t" << this << endl;
		}
		friend class Tree;
		friend class UniqueTree;
	}*Root;
	int i = 0;
public:
	Element* getRoot()
	{
		return Root;
	}
	Tree() :Root(nullptr)
	{
		cout << "TCon:\t" << this << endl;
	}
	~Tree()
	{

		cout << "TDes:\t" << this << endl;
	}

	void insert(int Data, Element* Root = nullptr)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}

	void print()const
	{
		if (this->Root == nullptr)return;

	}
	int minValue(Element* Root)
	{
		if (Root == nullptr)return 0;
		/*	if (Root->pLeft == nullptr)return Root->Data;
			else return minValue(Root->pLeft);*/
		return Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);

	}
	int maxValue(Element* Root)
	{
		if (Root == nullptr)return 0;
		return Root->pRight ? maxValue(Root->pRight) : Root->Data;
	}
	int Count(Element* Root)
	{

		if (Root == nullptr)return 0;
		else return Count(Root->pLeft) + Count(Root->pRight) + 1;
	}
	int Sum(Element* Root)
	{
		if (Root == nullptr)return 0;
		else return Sum(Root->pLeft) + Sum(Root->pRight) + Root->Data;
	}
	double Avg(Element* Root)
	{
		return (double)Sum(Root) / Count(Root);
	}
	int Depth(Element* Root)
	{
		if (Root == nullptr)return 0;
		if (Count(Root->pLeft) > Count(Root->pRight))return Count(Root->pLeft);
		else return Count(Root->pRight);
	}
	void Clear(Element* Root)
	{
		if (Root == nullptr)return;
		if (Root->pLeft)Clear(Root->pLeft);
		if (Root->pRight)Clear(Root->pRight);
		delete Root;

	}

};


class UniqueTree :public Tree
{
public:
	void insert(int Data, Element* Root = nullptr)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else if (Data > Root->Data)
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}

};


int main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "N = "; cin >> n;
	Tree tree;
	for (size_t i = 0; i < n; i++)
	{
		tree.insert(rand() % 100, tree.getRoot());
	}
	tree.print(tree.getRoot());
	NEXTLN;
	cout << "Min = " << tree.minValue(tree.getRoot()) << endl;
	cout << "Max = " << tree.maxValue(tree.getRoot()) << endl;
	cout << "Count = " << tree.Count(tree.getRoot()) << endl;
	cout << "AVG = " << tree.Avg(tree.getRoot()) << endl;
	cout << "Глубина = " << tree.Depth(tree.getRoot()) << endl;
	NEXTLN;
	UniqueTree tree2;
	for (size_t i = 0; i < n; i++)
	{
		tree2.insert(rand() % 100, tree2.getRoot());
	}
	tree2.print(tree2.getRoot());
	cout << "\nMin = " << tree2.minValue(tree2.getRoot()) << endl;
	cout << "Max = " << tree2.maxValue(tree2.getRoot()) << endl;
	cout << "Count = " << tree2.Count(tree2.getRoot()) << endl;
	cout << "Sum = " << tree2.Sum(tree2.getRoot()) << endl;
	cout << "AVG = " << tree2.Avg(tree2.getRoot()) << endl;
	cout << "Глубина = " << tree2.Depth(tree2.getRoot()) << endl;
	cout << "Удаление элементов = " << endl;
	tree2.Clear(tree2.getRoot());
	//tree2.print(tree2.getRoot());

}