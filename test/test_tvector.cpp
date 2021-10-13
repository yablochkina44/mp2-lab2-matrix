#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	//скопированный вектор равен исходному
	TVector <int> a(5);
	for (int i = 0; i < 5; i++)
		a[i] = i;
	TVector<int> b(a);
	EXPECT_EQ(a, b);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	//скопированный вектор имеет свою собственную память
	TVector <int> a(5);
	for (int i = 0; i < 5; i++)
		a[i] = i;
	TVector<int> b(a);
	a[0] = 5;
	EXPECT_NE(a, b);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	//исключение при установке элемента с отрицательным индексом
	TVector<int> m(5);
	ASSERT_ANY_THROW(m[-1]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	// ошибка когда задан элемент со слишком большим индексом
	TVector <int> a(5);
	ASSERT_ANY_THROW(a[100000003] = 1);
}

TEST(TVector, can_assign_vector_to_itself)
{
	// могу присвоить вектор самому себе
	TVector<int> a(4);
	for (int i = 0; i < 4; i++)
		a[i] = i * 2;
	EXPECT_EQ(a, a = a);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	// могу присвоить вектора одинаковых размеров
	TVector<int> a(4);
	TVector<int> b(4);
	a = b;
	EXPECT_EQ(a, b);
}

TEST(TVector, assign_operator_change_vector_size)
{
	//оператор присваивания изменяет размер вектора 
	TVector<int> a(2), b(4);
	for (int i = 0; i < 2; i++)
		a[i] = i * 10;
	b = a;
	EXPECT_EQ(2, b.GetSize());

}

TEST(TVector, can_assign_vectors_of_different_size)
{
	//могу prisvoit  вектора разных размеров
	TVector<int> a(5), b(7);
	for (int i = 0; i < 5; i++)
		a[i] = i * 10;
	b = a;
	EXPECT_EQ(a, b);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	//сравнение равных векторов
	TVector<int> a(4);
	TVector<int> b(4);
	for (int i = 0; i < 4; i++)
		a[i] = i * 10;
	for (int i = 0; i < 4; i++)
		b[i] = i * 10;

	EXPECT_EQ (1,a==b);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	//сравнение вектора с собой же
	TVector<int> a(4);
	EXPECT_EQ(1,a == a);

}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	//Векторы с разными размерами не равны
	TVector<int> a(3);
	TVector<int> b(4);
	EXPECT_NE(a, b);
 
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> a(4);
	TVector<int> b(4);
	for (int i = 0; i < 4; i++)
		a[i] = 2;
	a = a + 3;
	for (int i = 0; i < 4; i++)
		b[i] = 5;
	EXPECT_EQ(a, b);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> a(4);
	TVector<int> b(4);
	for (int i = 0; i < 4; i++)
		a[i] = 5;
	a = a - 3;
	for (int i = 0; i < 4; i++)
		b[i] = 2;
	EXPECT_EQ(a, b);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> a(4);
	TVector<int> b(4);
	for (int i = 0; i < 4; i++)
		a[i] = 2;
	a = a * 3;
	for (int i = 0; i < 4; i++)
		b[i] = 6;
	EXPECT_EQ(a, b);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	//могу сложить вектора с одинаковым размером
	TVector<int> a(3);
	for (int i = 0; i < 3; i++)
		a[i] = i;
	TVector<int> b(3);
	for (int i = 0; i < 3; i++)
		b[i] = i + 1;
	TVector<int> c(3);
	c = a + b;
	EXPECT_EQ(1, c[0]);
	EXPECT_EQ(3, c[1]);
	EXPECT_EQ(5, c[2]);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	//не могу сложить вектора с разным размером
	TVector<int> a(4), b(6);
	ASSERT_ANY_THROW(a + b);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	//могу вычесть вектора с одинаковым размером
	TVector <int> a(5), b(5), c(5);
	for (int i = 0; i < 5; i++)
		a[i] = 10;
	for (int i = 0; i < 5; i++)
		b[i] = 5;
	a = a - b;
	for (int i = 0; i < 5; i++)
		c[i] = 5;
	EXPECT_EQ(c, a);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	// не могу вычесть вектора с разными размерами
	TVector <int> a(5), b(6);
	ASSERT_ANY_THROW(a = a - b);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> a(4);
	for (int i = 0; i < 4; i++)
		a[i] = 1;
	TVector<int> b(4);
	for (int i = 0; i < 4; i++)
		b[i] = 4;
	int c;
	c = b * a;
	EXPECT_EQ(16, c);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> a(2);
	TVector<int> b(3);
	ASSERT_ANY_THROW(a * b);
}

