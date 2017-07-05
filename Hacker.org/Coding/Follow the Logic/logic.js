function ff(answer) {
    var x = 2;
    var y = 5;
    var z = 3;
    var a = new Array(6, 5, 4, 9, 3, 7);
    var v = y * a[y] + z * a[z] - y * x * z + a[y] * a[x] * a[3];
    a.reverse;
    v = v + a[z] + a[y] + 11 * a[1] + a[0] - 1;
    if (answer == v) {
        return true;
    } else {
        alert("not it!");
        return false;
    }
}
