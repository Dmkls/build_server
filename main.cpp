#include <iostream>
#include <fstream>
#include <string>

int main()
{
	string out_text = "Hello"
	string line;
	ofstream out;
	out.open("/var/www/testsite.dev/html/index.html");
	ifstream in("../template/template.html");
	
	if (in.is_open() && out.is_open())
	{
		while(getline(in, line))
		{
			if (line.find({"{text}"}) != string::npos)
				line = line.replace(line.find("{text}"), 6, out_text);
			out << line << endl;
		}
	}
	in.close();
	out.close();
	
	return 0;
}