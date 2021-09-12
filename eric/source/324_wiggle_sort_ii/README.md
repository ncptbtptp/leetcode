Solution 1:

sort, and turn (a1, a2, .., b1, b2, ..) to (a1, b1, a2, b2, ..).
The above is not accurate. Think this case: {4, 5, 5, 6}. In order for two medians (5) to be
separate as far as possible, instead of:
.5.6
4.5
we should form:
5.6
 4.5

That's why we need reverse it to be:
.6.5
5.4.

See? Even the sort solution is not easy. You need consider this case.


Solution 2:

find median first, then partition into three subarrays. [ < median ][ = median ][ > median]
you need form:  (m for median, s for small, b for big)
m.m.b.b
.s.s.m.m

and then reverse like above.


TODO:
O(1) space.
