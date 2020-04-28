#include <iostream>
using namespace std;

// pohranjivanje lista susjedstva cvora
struct Node {
	int val;
	Node* next;
};

// Pohranjivanje ivica grafa
struct Edge {
	int src, dest;
};

class Graph
{ 
	Node* getAdjListNode(int dest, Node* head)
	{
		Node* newNode = new Node;
		newNode->val = dest;

		// preusmjeravamo novi cvor na trenutnu glavu
		newNode->next = head;

		return newNode;
	}

	int N;	// broj cvorova u grafu

public:

	// Niz pointera/pokazivaca na cvor da prestave niz
	// lista susjedstva
	Node **head;

	// Konstruktor
	Graph(Edge edges[], int n, int N)
	{
		// alociraj memoriju
		head = new Node*[N]();
		this->N = N;

		for (int i = 0; i < N; i++)
			head[i] = nullptr;

		// dodaj ivicu u usmjereni graf
		for (unsigned i = 0; i < n; i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;

			// dodaj na pocetak
			Node* newNode = getAdjListNode(dest, head[src]);

			// point head pokazuje na novi node
			head[src] = newNode;

		 
		}
	}

	// destruktor
	~Graph() {
		for (int i = 0; i < N; i++)
			delete[] head[i];

		delete[] head;
	}
};

//ispisi sve susjedne vrhove danog tjemena
void printList(Node* ptr)
{
	while (ptr != nullptr)
	{
		cout << " -> " << ptr->val << " ";
		ptr = ptr->next;
	}
	cout << endl;
}

// implementacija grafa
int main()
{
	// niz ivica grafa
	Edge edges[] =
	{
		// par (x, y) predstavlja ivicu od x do y
		{ 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
		{ 3, 2 }, { 4, 5 }, { 5, 4 }
	};

	// broj vrhova u grafu
	int N = 6;

	// izracunaj broj ivica
	int n = sizeof(edges)/sizeof(edges[0]);

	// stvori graf
	Graph graph(edges, n, N);

	// ispisi listu susjedstva za predstavljanje grafa
	for (int i = 0; i < N; i++)
	{
		// ispisi dani vrh
		cout << i << " --";

		// ispisi sve susjedne vrhove
		printList(graph.head[i]);
	}

	cout << "\n\n Kod objasnjen u komentarima! \n";

	return 0;
}

