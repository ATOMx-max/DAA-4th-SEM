if(is_safe(x,k,i))
        {
            x[k]=i;
            if(k==n)
            {
                for(int i=1;i<=n;i++)
                {
                    printf("Row=%d Col=%d\n",i,x[i]);
                }
                printf("\n");
            }
            else
            {
                nqueen(x,k+1,n);
            }
        }