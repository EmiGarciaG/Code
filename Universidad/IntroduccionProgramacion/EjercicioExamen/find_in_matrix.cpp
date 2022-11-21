#include <iostream> 
using namespace std;

int find_in_matrix(float m[6][6],float valor){
	int n=0;
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
			if (m[i][j]==valor) n++;
	return n;
}

bool test_find_in_matrix(){
    cerr<<"testing..."<<__func__<<": ";
    float m[6][6]={ {1,1,1,1,1,1},{2,2,2,2,2,2},{3,3,3,3,3,3},{4,4,4,4,4,4},{5,5,5,5,5,5},{-1,6,6,6,6,6}};
    if (find_in_matrix(m,3)!=6)return false;
    if (find_in_matrix(m,-1)!=1)return false;
    return true;
}

int main(){
		if( test_find_in_matrix()) cout<<"Correcto"<<endl;
		else cout<<"Error"<<endl;
}