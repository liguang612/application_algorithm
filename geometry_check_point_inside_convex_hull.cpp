#include <iostream>
#include <vector>

using namespace std;

typedef struct Point
{
  int x;
  int y;

  Point() {}
  Point(int x, int y) : x(x), y(y) {}
} Point;

typedef struct Vector
{
  int x;
  int y;

  Vector() {};
  Vector(Point X, Point Y) :x(Y.x - X.x), y(Y.y - X.y) {};
} Vector;

int cross_product(Vector a, Vector b) {
  return a.x * b.y - a.y * b.x;
}

bool is_crossing(Point A, Point B, Point C, Point D) {
  return cross_product(Vector(A, B), Vector(A, C)) * cross_product(Vector(A, B), Vector(A, D)) < 0;
}

int crossing(Point A, Point B, Point C, Point D) {
  return cross_product(Vector(A, B), Vector(A, C)) * cross_product(Vector(A, B), Vector(A, D));
}

int main() {
  freopen("input.txt", "r", stdin);

  int left, mid, right, n, x, y;
  vector<Point> shape;

  cin >> n;
  shape.resize(n);

  for (int i = 0; i < n; i++)
  {
    cin >> x >> y;
    shape[i] = Point(x, y);
  }

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x >> y;

    Point p = Point(x, y);

    if (is_crossing(shape[0], shape[1], shape[2], p))
    {
      cout << 0 << endl;
      continue;
    }
    if (is_crossing(shape[0], shape[shape.size() - 1], shape[shape.size() - 2], p))
    {
      cout << 0 << endl;
      continue;
    }

    left = 0, right = shape.size() - 1;
    while (right > left + 1)
    {
      mid = (left + right) / 2;
      if (mid == 6) cout << crossing(shape[0], p, shape[1], shape[mid]) << endl;

      if (is_crossing(shape[0], p, shape[1], shape[mid]))
      {
        // cout << crossing(shape[0], p, shape[1], shape[mid]) << ": " << mid << '\n';
        right = mid;
        continue;
      }
      if (!is_crossing(shape[0], p, shape[1], shape[mid + 1]))
      {
        // cout << crossing(shape[0], p, shape[1], shape[mid + 1]) << ": " << mid << '\n';
        left = mid;
        continue;
      }

      break;
    }

    if (is_crossing(shape[mid], shape[mid + 1], shape[0], p))
    {
      cout << 0 << endl;
    }
    else {
      cout << 1 << endl;
    }
  }

  return 0;
}