 	
	int longestBitonicSubarray(int *input, int n) {
		
	/* Don't write main().
     	* the input is already passed as function argument.
     	* Taking input and printing output is handled automatically.
     	*/
     	
     	int x;
     	int inc[n]={0};
        int dec[n]={0};
        inc[0]=1;dec[n-1]=1;
        for(int i=1;i<n;i++)
        {
            inc[i]=1;
            for(int j=i-1;j>=0;j--)// THIS LOGIC IS FOR INCREASING SUBSEQUENCE IN WHICH WE NEED TO RUN INNER LOOP
            {
                if(input[j]>input[i])
                    continue;
                else if(input[j]<input[i])
                {
                    x=inc[j]+1;
                    if(x>inc[i])
                        inc[i]=x;
                }
            }
        }
        
        for(int i=n-2;i>=0;i--)
        {
            dec[i]=1;
            for(int j=i+1;j<=n-1;j++)// THIS LOGIC IS FOR DECREASING SUBSEQUENCE IN WHICH WE NEED TO RUN INNER LOOP
            {
                if(input[j]>input[i])
                    continue;
                else if(input[j]<input[i])
                {
                    x=dec[j]+1;
                    if(x>dec[i])
                        dec[i]=x;
                }
            }
        }
      /*  for (int i = 1; i < n; i++)  
        {
            inc[i] = (input[i] >= input[i-1])? inc[i-1] + 1: 1;//FOR SUBARRAY WE JUST NEED THE NEXT ELEMENT
        }
        
        for(int i=n-2;i>=0;i--)
        {
            dec[i]=(input[i]>input[i+1])? dec[i+1]+1:1;
        }
        
   /*     for(int i=0;i<n;i++)
        {
            cout<<inc[i];
        }
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<dec[i];
        }
        cout<<endl;*/
        int m=-1,z;
        for(int i=0;i<n;i++)
        {
            z=dec[i]+inc[i]-1;
            if(z>m)
                m=z;
        }

        return m;
 	}

