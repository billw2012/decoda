/*

Decoda
Copyright (C) 2007-2013 Unknown Worlds Entertainment, Inc. 

This file is part of Decoda.

Decoda is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Decoda is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Decoda.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "XmlUtility.h"

tinyxml2::XMLNode* WriteXmlNode(tinyxml2::XMLDocument & doc, const std::string& tag, const std::string& data, bool cdata)
{

    tinyxml2::XMLText* text = doc.NewText(data.c_str());
    text->SetCData(cdata);
  
	tinyxml2::XMLNode* node = doc.NewElement(tag.c_str());
    node->LinkEndChild(text);

    return node;

}

tinyxml2::XMLNode* WriteXmlNode(tinyxml2::XMLDocument & doc, const std::string& tag, int data)
{
    char temp[32];
    sprintf(temp, "%d", data);
    return WriteXmlNode(doc, tag, temp);
}