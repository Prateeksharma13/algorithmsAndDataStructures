console.log('getting here');



var a = "Idasdasdaswillwins,wins";
var b = "";
console.log(substrIndex(b, a));
console.log(endsWith(a));


function substrIndex(b, a) {
    var match = -1;
    var totalMatches =0;
    for (i = 0; i < a.length; i++) {
      if(match != -1 && a[i] == b[i-match]) {
        totalMatches +=1;
      }
      if(match == -1 && a[i] == b[0]) {
        match = i;
        totalMatches+=1;
      }
    }
    if(totalMatches == b.length) return match;
    return -1;
};


function titleCase(sentence) {
  sentence = sentence.toLowerCase().split(' ');
  for(var i = 0; i < sentence.length; i++){
    sentence[i] = sentence[i].split('');
    sentence[i][0] = sentence[i][0].toUpperCase();
    sentence[i] = sentence[i].join('');
  }
  return sentence.join(' ');
}

function endsWith(sentence) {
  sentence=a.split(',');
  return (sentence[0].substring(sentence[0].length-sentence[1].length, sentence[0].length) == sentence[1]);
}

