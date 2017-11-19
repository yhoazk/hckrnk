# Java streams

Wir haben einen Code von unserem Kunden bekommen und versuchen ihn zu verstehen. Kannst du uns sagen, was dieser Code macht? Dann hast du das Lösungswort.

```java
public static boolean function(final String s1, final String s2) {
	final Supplier<int[]> supplier = () -> {
		return IntStream.generate(() -> 0).limit(Character.MAX_VALUE).toArray();
	};
	final ObjIntConsumer<int[]> accumulator = (t, value) -> {
		t[value]++;
	};
	final BiConsumer<int[], int[]> combiner = (t, u) -> {
	};
	return Arrays.equals(
		s1.chars().collect(supplier, accumulator, combiner),
		s2.chars().collect(supplier, accumulator, combiner));
}
```
