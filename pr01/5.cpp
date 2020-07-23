int main()
{
    int count;
    std::cin >> count;
    Holder *p = new Holder[count];
    int bound = count / 2;
    for (int i = 0; i < bound; i++) {
        p[i].swap(p[count - i - 1]);
    }
    delete[] p;
    return 0;
}