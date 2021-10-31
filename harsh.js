console.time('time taken is');  //bracket ke undar wala chig same hona chayiea as timeEnd wala bracket aur agar nahi likhenge to default likhkar time print kar deta hain (default:_time_)
console.log('true');
console.log('1');
console.log('24*5');
console.log('56+2');
console.timeEnd('time taken is');
console.table({name: 'harsh' , marks: '34'})//represents data in tabular form...
console.warn('this is a warning');
console.error('this is an error');
alert('this is an alert');

                                 //Leacture 2

console.log('tut3');
// Variables in js
// var, let, const
var name = 'harry';
var channel;
var marks = 3454;
marks = 0;
channel = 'CodeWithHarry'
console.log(name, channel, marks);
// Rules for creating JavaScript Variables
/*
1. Cannot start with numbers
2. Can start with letter, numbers, _ or $
3. Are case sensitive
*/
var city = 'Delhi';
console.log(city);

const ownersName = 'Hari Ram';
// ownersName = 'Harry'; // Cannot do this (error)
console.log(ownersName);
const fruit = 'Orange';

{
 let city = 'Rampur';   
 city = 'Kolkata';
 console.log(city);
}
console.log(city);


const arr1 = [12,23,12,53, 3];
// arr1.push(45);
console.log(arr1)

/* Most common programming case types:

1. camelCase  
2. kebab-case
3. snake_case 
4. PascalCase 


*/