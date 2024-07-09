   i=0,e=s.length()-1,k;
        while(i<e)
        {
            while(i<e&&!isalnum(s[i])) s.erase(i,1);
            while(i<e&&!isalnum(s[e]))  s.erase(e,1);
            k=e;
            while(s[k]!=' ') k--;
            k++;
             while(s[i]!=' '||s[k]!='\0')
             {
                swap(s[i],s[k]);
             }
             if(s[i]==' ') s[k]='\0';
             
        }



          string reverseWords(string s) {
        i=0,e=s.length()-1,k,j;
        while(i<e&&s[i]==' ') {s.erase(i,1); e--;}
        while(i<e&&s[e]==' ') {s.erase(e,1); e--; }  //yaha pr e ki jagah s.length kr skte phir e minus krne ki zrurat nhi

        while(i<s.length()) //length isliye kyunki length might change
        {
            if(s[i]==' ')
            {
              j=i+1;
             while(s[j]==' ')) s.erase(j,1);
             i++;
             } 
             else
             {i++;}
        }
        i=0,e=s.length();
        while(i<e)
        {
            
        }

        
    }



    class Solution {
public:
    string reverseWords(string s) {
        int i=0,e=s.length()-1,k=0,j;
        string rev;
        while(i<e&&s[i]==' ') {i++;}
        while(i<e&&s[e]==' ') { e--;} 

        while(i<s.length())
        {
            if(s[i]==' ')
            {
              j=i+1;
             while(s[j]==' ')  j++;
             if(k!=0) rev.insert(0,s,k,i-k+1); //space will also be added
             else rev.insert(0,s,k,i-k); //if its first charcater it will go at last so no space needed 
             k=j;
             i=j;
             }
             else if(i==e) 
             {
                rev.insert(0," ");
               rev.insert(0,s,k,i-k+1); 
               i++;
             }
             else
                i++;
        }
      
        return rev;
    }
};