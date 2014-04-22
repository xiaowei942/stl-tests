#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int test_sort()
{
	cout<<"Now test sort"<<endl;
	vector <int> vecNum;

	//输入
	istream_iterator <int> cin_begin(cin), cin_end;
	copy(cin_begin, cin_end, back_inserter(vecNum));

	cin.clear();
	cin.sync();

	//排序
	sort(vecNum.begin(), vecNum.end());

	//输出
	ostream_iterator <int> cout_begin(cout, "\n");
	copy(vecNum.begin(), vecNum.end(), cout_begin);
	system("pause");
	cout<<"Now test sort end"<<endl;
	return 0;
}

int test_copy()
{
	cout<<"Now test copy"<<endl;
	int src[]= {1, 2, 3, 4, 5, 6, 7};  
	// vector<int> srcVec;  
	// srcVec.resize(7); 或者  
	vector<int> srcVec(src, src + 7); // 注意！7为长度  
	ostream_iterator<int> ofile(cout, " ");  
	// 将数值复制到vector里，参数依次是开始、结束，vector数组的开始  
	// (看起来src + 7越界了)src + 7 表示结束，srcVec.end()相当于src + 7  
	copy (src, src + 7, srcVec.begin());  

	cout << "srcVec contains:\n";  
	// 将数值复制到输出流中，参数依次是开始、结束，输出流  
	copy(srcVec.begin(), srcVec.end(), ofile);  
	cout << endl;  

	// 将数组向左移动两位  
	copy(src + 2, src + 7, src);  
	cout<< "shifting array sequence left by 2" << endl;  
	copy(src, src + 7, ofile);  
	cout << endl;  

	// 另一种方法，注意观察copy()中第二个参数  
	// srcVec.end()相当于src + 7  
	// 将数组向左移动两位  
	copy(srcVec.begin() + 2, srcVec.end(), srcVec.begin());  
	cout<< "shifting array sequence left by 2" << endl;  
	copy(srcVec.begin(), srcVec.end(), ofile);  

	cout<<"Now test copy end"<<endl;
	return 0;  
}

void main()
{
	test_copy();
	cout<<endl;
	test_sort();
	system("pause");
}