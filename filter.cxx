#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//dynamic allocation to read the data from the file noisy.txt into an array
void reading(double* const p, const int N, const string fname){
  ifstream in(fname.c_str());//create input file stream; ifstream is stream class to read from files
  
  for(int i=0; i<N; i++){
   in >> p[i];//store the values into an array 
  }
  
  in.close();//close input file stream
}

//filter function
//overwrite original array!
void filter(double* const p, const int N){
  p[0]=(p[0]+p[1])/3.0;
  double b=p[0];
  double a;//Puffer
  for(int i=1; i<(N-1); i++){
  a=p[i];
  p[i]=(b+p[i]+p[i+1])/3.0; 
  b=a;
  }
  p[N-1]=(p[N-2]+p[N-1])/3.0;
}

//write filtered data into a file called filtered.txt
//ofstream is stream class to write on files
void writing(double* const p, const int N){
  ofstream myfile;
  
  myfile.open ("filtered.txt");
  
  for(int i=0; i<N; i++)
  myfile << p[i] << endl;
  
  myfile.close();
}

int main(){
  const int N = 237;//current file has 237 lines
  const string filename = "noisy.txt";
  double* p = new double[N];
  
  reading(p, N, filename);
  
  //for(int i=0; i<N; i++)
    //cout << "p[" << i << "] =" << p[i] << endl;
  
  filter(p,N);
  
  writing(p,N);
  
  delete[] p;//free memory
  
  return 0;
}