var imp = require( '~/dext.js' );
base=JSON.parse('');

local = JSON.parse('');

remote = JSON.parse('');


function sortByKey(array, key) {
          return array.sort(function(a, b) {
          var x = a[key]; var y = b[key];
          return ((x < y) ? -1 : ((x > y) ? 1 : 0));
      });
  }

localRidTable = local.RidTable;
remoteRidTable = remote.RidTable;
//sortedlocaltable = sortByKey(localRidTable, 'Id');
sortedlocaltable = sortByKey(remoteRidTable, 'Id');

localSort = JSON.stringify(sortedlocaltable, null, 2);
//ls = JSON.stringify(remoteRidTable, null, 2);
console.log(localSort)
