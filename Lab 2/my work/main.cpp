#include <iostream>
#include <cmath>

using namespace std;

void showf1();
void showf2();
void showf3();
void showf4();
double fac(int);

int main(){
	cout<<"接下来的程序将通过迭代的方式找到最小的正整数N，使得 g(n) >= f(n) 对任何的 n>N."<<endl; 
	cout<<"分别有下列四组函数"<<endl;
	cout<<"1. n=1, f(n)=n and g(n)=nln(n)"<<endl ;
	cout<<"2. n=1, f(n)=n^10 and g(n)=2^n"<<endl ;
	cout<<"3. n=2, f(n)=n^10 and g(n)=n!"<<endl ;
	cout<<"4. n=2, f(n)=10^n and g(n)=n!"<<endl ;
	
	cout<<endl;
	
	cout<<"第一组函数："<<endl;
	showf1();
	cout<<"第二组函数："<<endl;
	showf2();
	cout<<"第三组函数："<<endl;
	showf3();
	cout<<"第四组函数："<<endl;
	showf4();
	
	return 0;
}

void showf1(){
	int n=1;
	double f,g;
	
	while(n<=10){
		f=n;
		g=n*log(n);
		cout<<"n"<<n<<": "<<"f(n"<<n<<")="<<f<<"    g(n"<<n<<")="<<g<<endl;
		if(g>f) break;
		++n;
	}
	
	if(n==11){
		cout<<"			."<<endl<<"			."<<endl<<"			."<<endl<<"			."<<endl<<"			."<<endl;
		while(1){
			f=n;
			g=n*log(n);
			if(g>f) {
				cout<<"n"<<n<<": "<<"f(n"<<n<<")="<<f<<"g(n"<<n<<")="<<g<<endl;
				break;
			}
			++n;
		}
	}
	
	cout<<endl;cout<<endl;
}
void showf2(){
	int n=1;
	double f,g;
	
	while(n<=10){
		f=pow(n,10);
		g=pow(2,n);
		cout<<"n"<<n<<": "<<"f(n"<<n<<")="<<f<<"    g(n"<<n<<")="<<g<<endl;
		if(g>f&&n>1) break;
		++n;
	}
	
	if(n==11){
		cout<<"			."<<endl<<"			."<<endl<<"			."<<endl<<"			."<<endl<<"			."<<endl;
		while(1){
			f=pow(n,10);
			g=pow(2,n);
			if(g>f) {
				cout<<"n"<<n<<": "<<"f(n"<<n<<")="<<f<<"    g(n"<<n<<")="<<g<<endl;
				break;
			}
			++n;
		}
	}
	
	cout<<endl;cout<<endl;
}
void showf3(){
	int n=1;
	double f,g;
	
	while(n<=10){
		f=pow(n,10);
		g=fac(n);
		cout<<"n"<<n<<": "<<"f(n"<<n<<")="<<f<<"    g(n"<<n<<")="<<g<<endl;
		if(g>f) break;
		++n;
	}
	
	if(n==11){
		cout<<"			."<<endl<<"			."<<endl<<"			."<<endl<<"			."<<endl<<"			."<<endl;
		while(1){
			f=pow(n,10);
			g=fac(n);
			if(g>f) {
				cout<<"n"<<n<<": "<<"f(n"<<n<<")="<<f<<"    g(n"<<n<<")="<<g<<endl;
				break;
			}
			++n;
		}
	}
	
	cout<<endl;cout<<endl;
}
void showf4(){
	int n=1;
	double f,g;
	
	while(n<=10){
		f=pow(10,n);
		g=fac(n);
		cout<<"n"<<n<<": "<<"f(n"<<n<<")="<<f<<"    g(n"<<n<<")="<<g<<endl;
		if(g>f) break;
		++n;
	}
	
	if(n==11){
		cout<<"			."<<endl<<"			."<<endl<<"			."<<endl<<"			."<<endl<<"			."<<endl;
		while(1){
			f=pow(10,n);
			g=fac(n);
			if(g>f) {
				cout<<"n"<<n<<": "<<"f(n"<<n<<")="<<f<<"    g(n"<<n<<")="<<g<<endl;
				break;
			}
			++n;
		}
	}
	
	cout<<endl;cout<<endl;
}


double fac(int n){
	return (n==0||n==1)? 1:n*fac(n-1);
}
