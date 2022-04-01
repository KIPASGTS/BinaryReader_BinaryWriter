# Writer Example
```c
//Writer Example
    BinaryWriter writer;
    writer.write_str("KIPASGTS");//name
    writer.write_int(19);//age
    writer.save_as("kipas.bin");
```

# Reader Example
```c
//Reader Example
    BinaryReader reader;
    reader.load_buff("kipas.bin");//file name
    string m_name = reader.read_str();
    int m_age = reader.read_int();
    cout << "Name: " << m_name << ", Age: " << m_age << endl;
    
    //Output
    //Name: KIPASGTS, Age: 19
```
