#include "LEDA/graph/graph.h"
#include "LEDA/graph/graph_gen.h"
#include "LEDA/graph/edge_array.h"
#include <iostream>
#include <fstream>
						//G..first_node G.last_node //new_edge//succesor_node//predesesor_node	G.join(g1)	//G.source(e)//G.target(e)	//G.source	

using namespace std;
using namespace leda;

int main()
{	
	leda::graph G;
	leda::grid_graph(G,10);
	for (int j = 0; j < 3; ++j)
	{
	
	leda::graph g1;
	leda::grid_graph(g1,10);

node u =G.last_node();

node v = g1.first_node();

//for (int i = 0; i < 3; ++i)
//{
//	v = G.pred_node(u);
//}
G.join(g1);

for (int i = 0; i < 10; ++i)
{
	G.new_edge(u,v);
	u = G.pred_node(u);
	v = G.succ_node(v);
}
}
ofstream mFile;
edge e;


mFile.open("mGraph.txt");
	mFile << "digraph G{" << endl;

	forall_edges(e,G){

		mFile << G.source(e)->id() << "->" << G.target(e)->id() << ";" << endl;
	}


	mFile << "}" << endl;

mFile.close();
	return 0;
}