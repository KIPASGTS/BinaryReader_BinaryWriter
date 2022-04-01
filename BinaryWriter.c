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
