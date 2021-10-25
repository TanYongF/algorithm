//字符串分割
vector<string> splitString(const string& str,const string& pattern)
{
	vector<string> result;
	//string::size_type型別，left：左邊界位置  right：右邊界位置 
	string::size_type left, right;
	right = str.find(pattern);
	left = 0;
	
	while(right != string::npos)
  	{
  		//以免字串首部就是分割依據，壓入長度為0的字串 
  		if(right-left)
  		{
  			//壓入起始位置為left，長度為（right-left）的字串 
    		result.push_back(str.substr(left, right-left)); 
  		}	
    	left = right + pattern.size();   //右邊界右移分割依據的長度，作為新的左邊界 
    	right = str.find(pattern, left);   //從left這個位置開始find 
  	}
  	
  	//退出迴圈時，左邊界不是最後一個元素 
  	if(left != str.length())
  	{
  		result.push_back(str.substr(left));
  	}
  	return result;    	
}