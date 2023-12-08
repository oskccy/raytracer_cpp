# raytracer_cpp

By: [*Oscar Sharaz Spencer*](https://www.linkedin.com/in/oscar-sharaz/)

ray tracer written in pure c++, which *generates and renders* simple three-dimensional objects. as this project is pretty hefty, myself and [Darius Desta](https://github.com/Darius808) have created thorough documentation for you to read. ***enjoy some renders!***

## Table of Contents
  - [1.0 must know 3D vector math operations](#must-know-operations)
    - [1.1 nature of 3d vectors](#the-nature-of-vectors)
    - [1.2 3d vector dot products (scalar output)](#vector-dot-products)
    - [1.3 3d vector cross products (vector output)](#vector-cross-products)
    - [1.4 normalized vector reflection equation](#vector-reflection-equation)
  - [2.0 project functionality](#project-functionality)
    - [2.1 3D vectors](#3d-vectors)
    - [2.2 light rays](#rays)
    - [2.3 hitable](#hitable)
    - [2.4 hitable list](#hitable-list)
    - [2.5 material](#material)
    - [2.6 sphere](#sphere)
    - [2.7 rendering bucket](#rendering-bucket)
  - [3.0 setup and usage](#setup-and-usage)
    - [3.1 cloning](#cloning)
    - [3.2 g++ compiling](#gpp-compiling-and-executing)
  - [4.0 contributions and suggestions](#contributions-and-suggestions)
## Must Know Operations
> in this section, I'll be going over the **must know mathematical concepts** that one must grasp to *understand the functionality of this ray tracer*.
### The Nature of Vectors
***Three-dimensional (3D) vectors*** are mathematical entities used to *represent quantities* that have both ***magnitude*** and ***direction*** in three-dimensional space. They are *fundamental in ray tracing*, in a 3D space, ***objects, positions, directions, and movements*** are defined using coordinates and vectors. Three-dimensional vectors are used to represent points in space, directions of rays, positions of lights, positions of objects, and more.

### Vector Dot Products
***The dot product***, also known as the *scalar product*, is an operation that takes two **3D vectors** and produces **a scalar** (single numerical value) as its result. The dot product is used to determine the similarity or alignment of two vectors and provides information about ***the angle*** between them. Here's how to calculate the dot product of two 3D vectors, typically denoted as A and B: 

Given two 3D vectors: 

$A = (Ax,  Ay,  Az)$ <br>
$B = (Bx,  By,  Bz)$ 

The dot product $A · B$ is computed as: $A · B = (AxBx) + (AyBy) + (AzBz)$


<p align="center">
  <kbd>
    <img src="https://github.com/oskccy/raytracer_cpp/assets/149972489/052775a9-418e-4c57-bd3e-1044d5859d62" alt="Thedotproduct" width="600">
  </kbd>
</p>

### Vector Cross Products
***The cross product***, also known as the *vector product*, is an operation that takes two ***3D vectors*** and produces ***a third vector*** as its result. This new vector is **orthogonal (perpendicular)** to both of the original vectors and provides valuable geometric information about their relationship. Here's how to calculate the cross product of two 3D vectors, typically denoted as A and B: 

Given two 3D vectors: 

$A = (Ax, Ay, Az)$ <br>
$B = (Bx, By, Bz)$ 

*Calculate the x-component of the resulting vector:* $AyBz - AzBy$

*Calculate the y-component of the resulting vector:* $AzBx - AxBz$

*Calculate the z-component of the resulting vector:* $AxBy - AyBx$

<p align="center">
  <kbd>
    <img src="https://github.com/oskccy/raytracer_cpp/assets/149972489/427d25e9-3e11-4da9-bedf-86d0c50b83fe" alt="thecrossproduct6" width="500">
  </kbd>
</p>

### Vector Reflection Equation
The ***normalized vector reflection equation*** is used to calculate the ***direction of a vector*** after it ***reflects off a surface***. This is a common concept in *physics, computer graphics, and geometry,* especially when dealing with light or objects bouncing off surfaces. The equation involves three main components: an incident vector, a surface normal vector, and the reflected vector.

**Incident Vector $(I)$**: The incident vector represents ***the initial direction*** of a vector, such as a ray of light or an object's velocity, before it interacts with a surface. The incident vector is typically denoted as **I**. 

**Surface Normal Vector $(N)$**: The surface normal vector represents ***the direction perpendicular to the surface*** at the point of reflection. It is often denoted as **N**. A surface normal vector is ***always a unit vector***, meaning it has a magnitude of 1, to ensure it represents only the direction. 

**Reflected Vector $(R)$**: The reflected vector represents ***the direction of the vector*** after it ***reflects*** off the surface. It is often denoted as $R$.

The normalized vector reflection equation is typically expressed as follows: R = $(I - 2)(I · N)N$

<p align="center">
  <kbd>
    <img src="https://github.com/oskccy/raytracer_cpp/assets/149972489/ba537c47-a75e-4959-93b6-52fee3aa2434" alt="normalizedvector" width="450">
  </kbd>
</p>

## Project Functionality
> in this section, I'll be going over **each component and class** of this ray tracer.
### 3D Vectors

### Rays

### Hitable

### Hitable List

### Material

### Sphere

### Rendering Bucket

## Setup and Usage
> in this section, I'll be going over **how to get, compile, and run** this ray tracer, as well as other information.
### Cloning
to *download the project locally*, copy/paste and **run the following** in cmd:
```bash
git clone https://github.com/oskccy/raytracer_cpp.git
ls
```
### GPP Compiling and Executing
to *view the code's render* (default or your own designs), <em><a href="https://www3.cs.stonybrook.edu/~alee/g++/g++.html">install the g++ compiler<a/></em> then run:
```bash
cd raytracer_cpp
ls
g++ main.cpp
```
depending on your designs, *this command could result in a **1 - 10 minute hang**.* ***(room for contributions here lmao)***

*macOS/Linux:*
```bash
ls
open render.ppm
```
*Windows:*
```bash
ls
start render.ppm
```

## Contributions and Suggestions
> contributing to this project would mean the world to me. *make this better*, ***sumbit pull requests***, because *im not a genius*. thank you so much!





