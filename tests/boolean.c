/*
TERMINATION

suggested parameters:
- partition abstract domain = boxes [default]
- function abstract domain = affine [default]
- backward widening delay = 2 [default]
*/

int main() {
  int x;
  while (x) {
    if (x > 0) {
      x = x - 1;
    } else {
      x = x + 1;
    }
  }
  return 0;
}