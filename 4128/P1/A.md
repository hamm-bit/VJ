# Week 1

From the samples, for the mumbles to make sense, they have to follow the order of natural numbers.
We can erect a 1-indexed loop to align with the number of given strings. If the string matches the number or mumbles it is ok. Vice versa, if the order is broken (i.e. at 4th position we got a '3') then its fishy.

The complexity of this algorithm is $O(n)$, directly correlated to the input size.

