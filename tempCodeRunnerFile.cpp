    map<int, int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); ++iter)
        cout << "<" << (*iter).first << "," << (*iter).second << ">" << " ";
    cout << endl;