#include <iostream>
#include <fstream>
using namespace std;
class BinaryReader {
public:
	BinaryReader() {
		m_index = 0;
	}
	~BinaryReader() {
		delete[] m_buff;
	}
	char* get_byte(const char* name) {
	    ifstream file;
	    file.open(name, ios::in | ios::binary);
	    file.seekg(0, ios::end);
	    auto size = (int)file.tellg();
        char* data = new char[size];
	    file.seekg(0, ios::beg);
	    file.read((char*)(data), size);
	    return data;
    }
	void load_buff(const char* filename) {
		m_buff = get_byte(filename);
	}
	short read_short() {
		short val = *(short*)(m_buff + m_index);
		m_index += sizeof(short);
		return val;
	}
	char read_char() {
		char val = *(char*)(m_buff + m_index);
		m_index += sizeof(char);
		return val;
	}
	int read_int() {
		int val = *(int*)(m_buff + m_index);
		m_index += sizeof(int);
		return val;
	}
	string read_str() {
		short nameLen = read_short();
		string data = "";
		for(int i = 0;i < nameLen;i++) data += m_buff[m_index++];
		return data;
	}
	char* m_buff;
	int m_index;
};
