#include <iostream>
#include <string>
using namespace std;

int getInt(string str){
    int value = 0;
    for (int i = 0; i < str.length(); i++) {
        value *= 10;
        value += (int(str[i]) - 48);
    }
    return value;
}

class BufferForRPN{
public:
    long long bufferIndex = -1;
    int subBuffer[1000];

    int getLastBufferValue(){
        return subBuffer[bufferIndex];
    }

    void addNewValue(int value){
        subBuffer[++bufferIndex] = value;
    }

    void valueErase(){
        subBuffer[bufferIndex] = 0;
        bufferIndex --;
    }

    void sumValue(){
        int temp = getLastBufferValue();
        valueErase();
        subBuffer[bufferIndex] += temp;
    }

    void diffValue(){
        int temp = getLastBufferValue();
        valueErase();
        subBuffer[bufferIndex] -= temp;
    }
};

int main(){
    string reversePN;
    getline(cin, reversePN);
    string subLine;
    BufferForRPN buffer;
    for (int i = 0; i < reversePN.length(); i ++){
        if (reversePN[i] != ' ' && reversePN[i] != '+' && reversePN[i] != '-'){
            subLine += reversePN[i];
        }
        else if (reversePN[i] == ' ' && subLine != ""){
            buffer.addNewValue(getInt(subLine));
            subLine = "";
        }
        else if (reversePN[i] == '+'){
            buffer.sumValue();
        }
        else if (reversePN[i] == '-'){
            buffer.diffValue();
        }
    }
    cout <<  buffer.subBuffer[buffer.bufferIndex] << endl;


}
