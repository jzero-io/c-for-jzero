package testdata

import (
	"fmt"
	"testing"
)

type Person struct {
	Name string
	Age  int
}

func TestSliceParam(t *testing.T) {
	persons := []Person{
		{
			Name: "John",
			Age:  20,
		},
		{
			Name: "Jane",
			Age:  30,
		},
	}

	bulkUpdateAge(persons)

	fmt.Println(persons)
}

func bulkUpdateAge(persons []Person) {
	for i := range persons {
		persons[i].Age++
	}
}
