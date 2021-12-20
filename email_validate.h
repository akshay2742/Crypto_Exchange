bool email_validate(char email[]){
    int At = -1, Dot = -1;
    int string_length(char email[])
    {
        int i, count=0;
        for (i = 0; email[i]!='\0'; i++)
        {
            count++;
        }
        return count;
    }
    bool isChar(char c)
    {
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
    }
    bool isDigit(const char c)
    {
        return (c >= '0' && c <= '9');
    }
    if (!isChar(email[0])) {
        return 0;
    }


    for (int i = 0;i<string_length(email);i++) {
        if (email[i] == '@') {

            At = i;
        }
        else if (email[i] == '.') {

            Dot = i;
        }
    }

    if (At == -1 || Dot == -1)
        return 0;

    if (At > Dot)
        return 0;

    return !(Dot >= (string_length(email) - 1));
}
