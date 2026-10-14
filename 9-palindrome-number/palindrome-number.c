
bool isPalindrome(int x) {
    double rem, rev =0,orig=x;
    while( x>0){
        rem = x % 10;
        rev = rev *10 + rem;
        x/=10;
    }
    if(rev==orig){
        return true;
    }
    else{
        return false;
    } 

        

    }
    