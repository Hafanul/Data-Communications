class Sender{
    string data;
    string divisor = "11101101101110001";
    string frame;
    int st = 0;
public:
    void create_data()
    {
        for(int i=0; i<1000; i++){

            int random = rand() % 2; //Generating Random number (0 or 1)
            int f = random;
            char c = f + '0';
            this->data += c;
        }

    }
    void CRC()
    {
        string temp;
        int k = this->st;
        while(this->st<(k+100))
        {
            temp+=this->data[st];
            this->st++;
        }
        frame = temp;
        //cout<<temp<<endl;
        int d = this->divisor.size();
        for(int i=0;i<d-1;i++)
        {
            temp += '0';
        }
        //cout<<temp<<endl;
        for(int i=0; i<=temp.size()-d; i++){
            for(int j=0; j<d; j++){
                if(temp[i+j] == divisor[j])
                    temp[i+j] = '0';
                else
                    temp[i+j] = '1';
            }
            while(i==temp.size() && temp[i]==1){
                i++;
            }
        }

        for(int i=temp.size()-d+1; i<temp.size(); i++){
            frame += temp[i];
        }
        //cout<<frame<<endl;
    }
    string getframe()
    {
        return this->frame;
    }
    string getdata()
    {
        return this->data;
    }
    void showData()
    {
        cout<<this->data<<endl<<endl;
    }

};
