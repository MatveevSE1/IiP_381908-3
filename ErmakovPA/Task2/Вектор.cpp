#include "Matrix.h"

int main()
{
    srand((unsigned int)time(0));

    int n;
    cout << "Vector size" << endl;
    do {
        cin >> n;
    } while (n < 3);
    Vector v1(n), v2(n), sum(n), resVec(n);
    double res;
    cout << "Vector 1" << endl;
    cin >> v1;
    cout << "Vector 2" << endl;
    cin >> v2;
    Vector* jopa = new Vector[n];

    cout << endl << "Lenght between vectors   " << v1.betweenthebars(v2) << endl << endl;

    sum = v1 + v2;
    cout << "Sum result   " << sum << endl;

    sum = v1 - v2;
    cout << "Subtraction result   " << sum << endl;

    res = v1 * v2;
    cout << "Inner product result   " << res << endl;
    jopa[2] = v2;
    jopa[1] = v1;
    for (int i = 3; i < n; i++)
    {
        v2.Random();
        jopa[i] = v2;
    }

    resVec = v1.VecMult(jopa);
    cout << endl << "Vector Mult result   " << resVec << endl;

    Matrix m1(n, n), m2(n, n), m3;
    Matrix ress(n, n);
    for (int i = 0; i < n; i++)
    {
        v1.Random();
        v2.Random();
        m1.Set(v1, i);
        m2.Set(v2, i);
    }

    cout << endl;
    cout << "Matrix generatin" << endl;
    m1.MOut();
    cout << endl;
    m2.MOut();
    cout << endl;

    cout << "Matrix sum" << endl;

    ress = m1 + m2;
    cout << endl;
    ress.MOut();

    cout << "Matrix subtraction" << endl;

    ress = m1 - m2;
    cout << endl;
    ress.MOut();

    cout << "Matrix multiplication by 2" << endl;

    ress = ress * 2;
    cout << endl;
    ress.MOut();

    cout << "Matrix multiplication" << endl;

    ress = m1 * m2;
    cout << endl;
    ress.MOut();

    cout << "Matrix division" << endl;

    ress = m1 / m2;
    cout << endl;
    ress.MOut();

    cout << "first Matrix in degree 3" << endl;

    ress = m1 ^ 3;
    cout << endl;
    ress.MOut();
}
