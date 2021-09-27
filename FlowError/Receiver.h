class Receiver{
    string data;
    string divisor = "11101101101110001";
    string frame;
    int ACK=0;
public:
    int receive_frame(int i, string f)
    {
        string temp;
        if(i < ACK)
        {
            cout<<"\t\t\t\t\t\tDuplicate Data Received... Ignoring One..."<<endl;
            Sleep(TIME);
            cout<<"\t\t\t\t\t\tAcknowledgment sent for Frame: "<<ACK<<endl<<endl;
            return ACK;

        }
        else
        {
            this->frame = f;
            temp = f;
        }
        //cout<<temp<<endl;
        int d = this->divisor.size();
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
        string t;
        for(int i=temp.size()-d+1; i<temp.size(); i++){
            t += temp[i];
        }
        //cout<<t<<endl;
        for(int i=0;i<t.size();i++)
        {
            if(t[i]=='1')
            {
                frame.empty();
                cout<<"\t\t\t\t\t\tFrame: "<<ACK+1<<" is lost..."<<endl;
                Sleep(TIME);
                cout<<"\t\t\t\t\t\tResend the Data..."<<endl;
                Sleep(TIME);
                return -1;
            }
        }

        int U=100,L=1;
        int random = (rand() % (U-L+1))+L;
        if(random<20)
        {
            ACK++;
            cout<<"\t\t\t\t\t\tReceived..."<<endl;
            cout<<"\t\t\t\t\t\tAcknowledgment sent for Frame: "<<ACK<<endl<<endl;
            addData();
            return 0;
        }
        else
        {
            ACK++;
            cout<<"\t\t\t\t\t\tReceived..."<<endl;
            Sleep(TIME);
            cout<<"\t\t\t\t\t\tAcknowledgment sent for Frame: "<<ACK<<endl<<endl;
            addData();
            return ACK;
        }
    }

    void addData()
    {
        string d;
        for(int i=0;i<100;i++)
        {
            d += this->frame[i];
        }
        this->data += d;
        return;
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
