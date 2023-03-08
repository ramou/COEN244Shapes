#include "MultiShape.h"
MultiShape operator+(Shape& s1, Shape& s2) {
	MultiShape m;
	m << s1 << s2;
	return m;
}
//Delegation is cool, but gives us the wrong order!
//MultiShape operator+(Shape& s1, MultiShape m) {
//  return m + s1;
//}

MultiShape operator+(Shape& s1, MultiShape m) {
	MultiShape m2;
	m2 << s1;
	std::for_each(
		m.shapes.begin(),
		m.shapes.end(), [&m2](Shape* s) {
			m2.add(*s);
		});
	//m2 << s1 << m;
	return m2;
}
