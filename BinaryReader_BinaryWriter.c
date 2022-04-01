#include <iostream>
#include <fstream>
using namespace std;
class BinaryWriter {
public:
	BinaryWriter() {
		m_index = 0;
		m_buff = new uint8_t[1];
	}
	~BinaryWriter() {
		delete[] m_buff;
	}
	void write_char(char val) {
		m_buff[m_index] = (char)val;
		m_index++;
	}
	void write_short(short val) {
		memcpy(m_buff + m_index, &val, sizeof(short));
		m_index += sizeof(short);
	}
	void write_int(int val) {
		memcpy(m_buff + m_index, &val, sizeof(int));
		m_index += sizeof(int);
	}
	void write_str(const char* text) {
		write_short(strlen(text));
		memcpy(m_buff + m_index, text, strlen(text));
		m_index += strlen(text);
	}
	
	void save_as(const char* name) {
		FILE *a = fopen(name, "wb");
	    fwrite(m_buff, sizeof(uint8_t), m_index, a);
	    fclose(a);
	}
	uint8_t* m_buff;
	int m_index;
};
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
