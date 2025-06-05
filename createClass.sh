#!/bin/bash

#Check input
if [ $# -lt 2 ]; then
	echo "How to use: ./createClass.sh <class name> <folder>"
	exit 1
fi

#Name and destiny
CLASSNAME=$1
FOLDER=$2

#Colours
ORANGE='\033[38;5;208m'
RESET='\033[0m'

#copy files
cp ClassTemplate.hpp ${CLASSNAME}.hpp
cp ClassTemplate.cpp ${CLASSNAME}.cpp

#Replace CLASSNAME
sed -i "s/ClassTemplate/${CLASSNAME}/g" ${CLASSNAME}.hpp
sed -i "s/ClassTemplate/${CLASSNAME}/g" ${CLASSNAME}.cpp
sed -i "s/CLASSTEMPLATE_HPP/$(echo ${CLASSNAME} | tr '[:lower:]' '[:upper:]')_HPP/g" ${CLASSNAME}.hpp

echo -e "Class: ${ORANGE}${CLASSNAME}${RESET} successfuly created!"

mv ${CLASSNAME}.hpp ${FOLDER}/includes
mv ${CLASSNAME}.cpp ${FOLDER}/src
