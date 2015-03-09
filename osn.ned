//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package sor1;
//@namespace(sor1);

network osn
{
    @display("i=abstract/people2");
    types:
        channel Channel extends ned.DelayChannel {
            delay = 100ms;
        }
    submodules:
        n[6]: node1;
    connections:
        n[0].gate++ <--> Channel <--> n[1].gate++;
        n[1].gate++ <--> Channel <--> n[2].gate++;
        n[2].gate++ <--> Channel <--> n[3].gate++;
        n[3].gate++ <--> Channel <--> n[4].gate++;
        n[4].gate++ <--> Channel <--> n[5].gate++;
        n[5].gate++ <--> Channel <--> n[0].gate++;
}

