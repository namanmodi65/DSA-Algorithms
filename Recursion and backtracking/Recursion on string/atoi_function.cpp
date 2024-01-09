long atoi(string s, int sign, int i, long result)
{

    if (sign * result >= INT_MAX)
    {

        return INT_MAX;
    }

    if (sign * result <= INT_MIN)
    {

        return INT_MIN;
    }

    if (i >= s.size() || s[i] < 48 || s[i] > 57)
    {

        return sign * result;
    }

    return atoi(s, sign, i + 1, (result * 10 + (s[i] - 48)));
}

int createAtoi(string s)
{

    int i = 0, n = s.size(), sign = 1;

    while (i < n && s[i] == ' ')

        ++i;

    if (s[i] == '-')

        sign = -1, ++i;

    else if (s[i] == '+')

        ++i;

    return atoi(s, sign, i, 0);
}