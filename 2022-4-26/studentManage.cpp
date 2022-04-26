#include<bits/stdc++.h>
using namespace std;

int main()
{
	string fileContent[100];

	int modeSel, fileLineNum;
	string strInput, fileLine;

	int i;

	do {
		// system("cls");
		cout << "\t\t---------------------------------------------------------------------------------------" << endl << endl;
		cout << "\t\t\t请输入想要进行的操作：" << endl << endl;
		cout << "\t\t\t1、显示当前文件中的内容" << endl;
		cout << "\t\t\t2、向文件中写入新的内容" << endl;
		cout << "\t\t\t3、清空文本中已有的内容" << endl;
		cout << "\t\t\t4、结束当前所有操作" << endl;
		cout << "\t\t---------------------------------------------------------------------------------------" << endl;
		cout << endl << "\t\t\t";

		cin >> modeSel;
		cout << endl;

		ifstream myFileIn("A3_data.dat");
		if (!myFileIn) {
			cout << "无法打开输入文件！" << endl;
			return -1;
		}
		fileLineNum = 0;
		while (getline(myFileIn, fileLine))
		{
			fileContent[fileLineNum] = fileLine;
			fileLineNum++;
		}

		switch (modeSel)
		{
		case 1:
			cout << "\t\t\t//当前文本内有如下内容：//" << endl;
			cout << "\t\t---------------------------------------------------------------------------------------" << endl << endl;
			for (i = 0; i < fileLineNum; i++) {
				cout << "\t\t\t" << fileContent[i] << endl;
			}
			cout << endl << "\t\t---------------------------------------------------------------------------------------" << endl << endl;
			break;

		case 2:
			cout << "\t\t\t请输入希望添加进文本的内容：\t";
			//cout << endl << endl;
			cin >> strInput;
			cout << endl;
			fileContent[fileLineNum] = fileLine;
			fileLineNum++;
			cout << "\t\t\t内容添加已完成......" << endl << endl;
			break;

		case 3:
			fileLineNum = 0;
			cout << "\t\t\t文件内容已清除......" << endl << endl;
			break;

		case 4:
			exit(0);
			break;

		default:
			cout << "\t\t\t输入错误，请重新输入：" << endl << endl;
			break;
		}
		ofstream myFileOut("A3_data.dat");
		if (!myFileOut) {
			cout << "无法打开输入文件！" << endl;
			return -1;
		}
		for (i = 0; i < fileLineNum; i++) {
			myFileOut << fileContent[i] << endl;
		}
		myFileIn.close();
		myFileOut.close();
		system("pause");
	} while (modeSel != 4);
	
	return 0;
}
