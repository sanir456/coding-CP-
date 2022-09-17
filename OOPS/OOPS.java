public class OOPS {
    public static void main(String args[])
    {
        // -----------------------------------------------------------------------------
        // polymorphism
        // Student s1 = new Student();
        // s1.name="Sani";
        // s1.age=22;

        // // compiletime polymorphism
        // s1.printInfo();
        // s1.printInfo(s1.name);

        // runtime polymorphism
        Monitor s2 = new Monitor();
        new MOniter();
        // s2.name = "Ravi";
        // s2.age = 25;
        // s2.printInfo();
        // Student s3 = s2;
        // s3.name = "puja";
        // s3.age = 20;
        // s3.printInfo();

        // // used parent class override mathod using child class
        // s2.printInfoStudent();
        

        
        // -----------------------------------------------------------------------------
        // inheritance
        // Triangle t1 = new Triangle();
        // t1.color = "red";
        // t1.area(2,4);
        // EquilateralTriangle e1 = new EquilateralTriangle();
        // e1.color = "red";
        // e1.area(2);
        // Circle c1 = new Circle();
        // c1.color = "red";
        // c1.area(7);


        // -----------------------------------------------------------------------------
        //Encapsulation
        // Account a1 = new Account();
        // a1.name = "Sani";
        // a1.email = "saniranpariya@gmail.com"; 
        // a1.setPass("asd");
        // System.out.println(a1.getPass());


        // -----------------------------------------------------------------------------
        // Abstraction
        // Horse h1 = new Horse();
        // h1.walk();

        // Chicken c1 = new Chicken();
        // c1.walk();

      
    }

}

// ploymorphism
class Student {
    String  name;
    int age;

    // constructer buz we defined copy constructer.
    //start
    Student()
    {
        System.out.println("Student");
    }

    Student(String name,int age)
    {
        this.name = name;
        this.age = age;
    }

    Student(Student s)
    {
        this.name=s.name;
        this.age = s.age;
    }
    //end

    // compile-time polymorphism
    //start
    public void printInfo()
    {
        System.out.println("Name: "+this.name);
        System.out.println("Age: "+this.age);
    }

     public void printInfo(String name)
    {
        System.out.println("Name: " + name);
    }

    public void printInfo(int age)
    {
        System.out.println("age: " + age);
    }

    
    public void printInfo(String name,int age)
    {
        System.out.println("Name: " + name);
        System.out.println("age: " + age);
    }
    //end
}

class Monitor extends Student {
    
    // for runtime polymorphism 
    Monitor()
    {
        System.out.println("moniter");
    }

    public void printInfo()
    {
        System.out.println("Name: "+this.name);
        System.out.println("Age: "+this.age);
        System.out.println("He/She is class montior");
    }

    public void printInfoStudent()
    {
        super.printInfo();
    }
    public void checkHW()
    {
        System.out.println("Check Homework");
    }

}


//inheritance
class Shape {
    String color;
    public void area()
    {
        System.out.println("display area");
    }
}

// single
class Triangle extends Shape {
    public void area(int l,int h)
    {
        System.out.println("Area: " + (1/2.0)*(l*h));
    }
}

//multilevel
class EquilateralTriangle extends Triangle {
    public void area(int l)
    {
        System.out.println("Area: " + (Math.sqrt(3)/4)*(l*l));
    }
}

//multiple
class Circle extends Shape {
    public void area(int r)
    {
        System.out.println("Area:" + 3.14*r);
    }

}



// Encapsulation
class Account {
    public String name;
    protected String email;
    private String pass;

    //getter and setter
    public String getPass()
    {
        return this.pass;
    }   

    public void setPass(String pass)
    {
        this.pass=pass;
    }
}


//abstraction
// abstract class Animal {
//     Animal()
//     {
//         System.out.println("Animal Created");
//     }
//     abstract void walk();
// }

// class Horse extends Animal {
//     Horse()
//     {
//         System.out.println("Horse Created");
//     }
//     public void walk()
//     {
//         System.out.println("Walked on four legs");
//     }
// }

// class Chicken extends Animal {
//     Chicken()
//     {
//         System.out.println("Chicken Created");
//     }
//     public void walk()
//     {
//         System.out.println("Walked on two legs");
//     }
// }


interface Animal {
    void walk();
  
}

class Horse implements Animal {
    public void walk(){
        System.out.println("Walked on four legs");
    }
}

class Chicken implements Animal {
    public void walk(){
        System.out.println("Walked on two legs");
    }
}