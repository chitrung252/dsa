// https://stackoverflow.com/questions/29136286/no-viable-conversion-from-class-to-class-c

ClassFoo foo; // local variable at stack
ClassFoo \*foo = new ClassFoo(); // local pointer to some memory at heap which is structured like ClassFoo

     C++ is not Java(or C #I suppose)
            .You should never use the new keyword unless you know that you need to.And it returns a pointer to the newly created class,
    hence the error you get.Likely, the following would be sufficient :

    Class foo;

someFunction(foo);
