// array methods
//map
// filter
// reduce

//=> arrow function



//map it maps the elemets and change evary elament or iterate every element

// const ourarray = [1,2,3,4,5];

// const neyarray = ourarray.map((data)=>{
//     return data +10;
// });

// console.log(neyarray)



//filter
// it is used to filter the elements like we did hear using < operator


// const ourarray = [1,2,3,4,5];

// const neyarray = ourarray.filter((data)=>{
//     return data <3 ;
// });

// console.log(neyarray)




// reduce
// it only return 1 value either one value , or might be a string etc
// it is like a loop and it iterates till we add all elments acummulator stores the nect value and current value stores the current value after the addition 
// these name are choise we can use any of our wish but is is recomended to use those names

// const ourarray = [1,2,3,4,5];

// const newarray = ourarray.reduce((accumulator,currentval)=>{
//     return accumulator + currentval;
// },0);

// console.log(newarray);
// console.log(ourarray);

// promises

// it either rejects or resolves th promises but after some time

let concert = true;

let attendConcert = new Promise((resolve , reject)=>{
    setTimeout(()=>
    {
        if (concert) resolve ("we did attend the cencert");
        else reject("we failed to attend");

    },2000);

});

// then and catch to make the output

// then to make the out put come if there is any output
attendConcert.then((sujay)=> console.log(sujay));
// it catches the error itf there is any
attendConcert.catch((Error)=> console.log(Error));

// async and await are promises

