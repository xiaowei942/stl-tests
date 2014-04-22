#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int test_sort()
{
	cout<<"Now test sort"<<endl;
	vector <int> vecNum;

	//����
	istream_iterator <int> cin_begin(cin), cin_end;
	copy(cin_begin, cin_end, back_inserter(vecNum));

	cin.clear();
	cin.sync();

	//����
	sort(vecNum.begin(), vecNum.end());

	//���
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
	// srcVec.resize(7); ����  
	vector<int> srcVec(src, src + 7); // ע�⣡7Ϊ����  
	ostream_iterator<int> ofile(cout, " ");  
	// ����ֵ���Ƶ�vector����������ǿ�ʼ��������vector����Ŀ�ʼ  
	// (������src + 7Խ����)src + 7 ��ʾ������srcVec.end()�൱��src + 7  
	copy (src, src + 7, srcVec.begin());  

	cout << "srcVec contains:\n";  
	// ����ֵ���Ƶ�������У����������ǿ�ʼ�������������  
	copy(srcVec.begin(), srcVec.end(), ofile);  
	cout << endl;  

	// �����������ƶ���λ  
	copy(src + 2, src + 7, src);  
	cout<< "shifting array sequence left by 2" << endl;  
	copy(src, src + 7, ofile);  
	cout << endl;  

	// ��һ�ַ�����ע��۲�copy()�еڶ�������  
	// srcVec.end()�൱��src + 7  
	// �����������ƶ���λ  
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