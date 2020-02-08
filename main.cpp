#include "custom.h"
main(){
    ////////////////////////////////////////////////////////////////////////////////////////////
    // intro - module
    initwindow(1020, 270, "Welcome! Periodic Table, A Project By HyphenSaad");
    cout << "> Press Enter Key To Continue..." << endl;
    drawMPTL(75,75,10);
    closegraph(CURRENT_WINDOW);

    ////////////////////////////////////////////////////////////////////////////////////////////
    // data processing - module
    RERUN:

	// local variables
	string atomicNumber, atomicRadius, atomicWeight, block, boilingPoint, density, electroNegativity,
	electronicConfiguration, elementSymbol, group, meltingPoint, elementName, input = "";
	int elementNumber = 0;
	char option;

	NOINPUT:

	// to get input from files
	fstream inputDataFileObj;
	inputDataFileObj.open("input.txt", ios::in);
	getline(inputDataFileObj, input);
	inputDataFileObj.close();

	// to check if input file is empty
    if(input == ""){
        cout << "> No input in file..." << endl;
        A:
        cout << "> Enter 0 To Check Again..." << endl;
        cout << "> Enter x To Exit...";
        char check = ' ';
        cin >> check;
        if(check == '0'){
            goto NOINPUT;
        } else if(check == 'x' || check == 'X'){
            exit(1);
        } else {
            cout << "> Invalid! Command..." << endl;
            goto A;
        }
    }

	// to find the entered element symbols, location in periodic table
	fstream byElementSymbolDataFile;
	byElementSymbolDataFile.open("data/elementSymbol.txt", ios::in);

	for(int i = 0 ; i < TOTAL_ELEMENTS ; i++){
		getline(byElementSymbolDataFile, elementSymbol);
		if(elementSymbol == input){
			elementNumber = i + 1;
		}
	}

	byElementSymbolDataFile.close();

	// to find the entered atomic number, location in periodic table
	fstream byAtomicNumberDataFile;
	byAtomicNumberDataFile.open("data/atomicNumber.txt", ios::in);

	for(int i = 0 ; i < TOTAL_ELEMENTS ; i++){
		getline(byAtomicNumberDataFile, atomicNumber);
		if(atomicNumber == input){
			elementNumber = i + 1;
		}
	}

	byAtomicNumberDataFile.close();

	// to get element name
	fstream elementNameDataFile;
	elementNameDataFile.open("data/elementName.txt", ios::in);
	GotoLine(elementNameDataFile, elementNumber);
	getline(elementNameDataFile, elementName);
	elementNameDataFile.close();

	// to get atomic number
	fstream atomicNumberDataFile;
	atomicNumberDataFile.open("data/atomicNumber.txt", ios::in);
	GotoLine(atomicNumberDataFile, elementNumber);
	getline(atomicNumberDataFile, atomicNumber);
	atomicNumberDataFile.close();

	// to get atomic radius
	fstream atomicRadiusDataFile;
	atomicRadiusDataFile.open("data/atomicRadius.txt", ios::in);
	GotoLine(atomicRadiusDataFile, elementNumber);
	getline(atomicRadiusDataFile, atomicRadius);
	atomicRadiusDataFile.close();

	// to get atomic weight
	fstream atomicWeightDataFile;
	atomicWeightDataFile.open("data/atomicWeight.txt", ios::in);
	GotoLine(atomicWeightDataFile, elementNumber);
	getline(atomicWeightDataFile, atomicWeight);
	atomicWeightDataFile.close();

	// to get block
	fstream blockDataFile;
	blockDataFile.open("data/block.txt", ios::in);
	GotoLine(blockDataFile, elementNumber);
	getline(blockDataFile, block);
	blockDataFile.close();

	// to get boilingPoint
	fstream boilingPointDataFile;
	boilingPointDataFile.open("data/boilingPoint.txt", ios::in);
	GotoLine(boilingPointDataFile, elementNumber);
	getline(boilingPointDataFile, boilingPoint);
	boilingPointDataFile.close();

	// to get density
	fstream densityDataFile;
	densityDataFile.open("data/density.txt", ios::in);
	GotoLine(densityDataFile, elementNumber);
	getline(densityDataFile, density);
	densityDataFile.close();

	// to get electronegativity
	fstream electronegativityDataFile;
	electronegativityDataFile.open("data/electronegativity.txt", ios::in);
	GotoLine(electronegativityDataFile, elementNumber);
	getline(electronegativityDataFile, electroNegativity);
	electronegativityDataFile.close();

	// to get electronic configuration
	fstream electronicConfigurationDataFile;
	electronicConfigurationDataFile.open("data/electronicConfiguration.txt", ios::in);
	GotoLine(electronicConfigurationDataFile, elementNumber);
	getline(electronicConfigurationDataFile, electronicConfiguration);
	electronicConfigurationDataFile.close();

	// to get elementSymbol
	fstream elementSymbolDataFile;
	elementSymbolDataFile.open("data/elementSymbol.txt", ios::in);
	GotoLine(elementSymbolDataFile, elementNumber);
	getline(elementSymbolDataFile, elementSymbol);
	elementSymbolDataFile.close();

	// to get group
	fstream groupDataFile;
	groupDataFile.open("data/group.txt", ios::in);
	GotoLine(groupDataFile, elementNumber);
	getline(groupDataFile, group);
	groupDataFile.close();

	// to get melting point
	fstream meltingPointDataFile;
	meltingPointDataFile.open("data/meltingPoint.txt", ios::in);
	GotoLine(meltingPointDataFile, elementNumber);
	getline(meltingPointDataFile, meltingPoint);
	meltingPointDataFile.close();

	// to add units
	atomicWeight += " amu";
	boilingPoint += " C";
	meltingPoint += " C";

    ////////////////////////////////////////////////////////////////////////////////////////////
    // save result to file - module
    fstream outputDataFile;
    outputDataFile.open("output.txt", ios::out);
    outputDataFile << "+-------------------------------+------------------------------------+" << endl;
    outputDataFile << "|    Element Name               |    " << elementName;
    for(int i = 0 ; i < (32 - elementName.length()) ; i++){
        outputDataFile << " ";
    }
    outputDataFile << "|" << endl;
    outputDataFile << "+-------------------------------+------------------------------------+" << endl;
    outputDataFile << "|    Atomic Number              |    " << atomicNumber;
    for(int i = 0 ; i < (32 - atomicNumber.length()) ; i++){
        outputDataFile << " ";
    }
    outputDataFile << "|" << endl;
    outputDataFile << "+-------------------------------+------------------------------------+" << endl;
	outputDataFile << "|    Atomic Radius              |    " << atomicRadius;
    for(int i = 0 ; i < (32 - atomicRadius.length()) ; i++){
        outputDataFile << " ";
    }
    outputDataFile << "|" << endl;
	outputDataFile << "+-------------------------------+------------------------------------+" << endl;
	outputDataFile << "|    Atomic Weight              |    " << atomicWeight;
	for(int i = 0 ; i < (32 - atomicWeight.length()) ; i++){
        outputDataFile << " ";
    }
    outputDataFile << "|" << endl;
	outputDataFile << "+-------------------------------+------------------------------------+" << endl;
	outputDataFile << "|    Block                      |    " << block;
	for(int i = 0 ; i < (32 - block.length()) ; i++){
        outputDataFile << " ";
    }
    outputDataFile << "|" << endl;
	outputDataFile << "+-------------------------------+------------------------------------+" << endl;
	outputDataFile << "|    Boiling Point              |    " << boilingPoint;
	for(int i = 0 ; i < (32 - boilingPoint.length()) ; i++){
        outputDataFile << " ";
    }
    outputDataFile << "|" << endl;
	outputDataFile << "+-------------------------------+------------------------------------+" << endl;
	outputDataFile << "|    Density                    |    " << density;
	for(int i = 0 ; i < (32 - density.length()) ; i++){
        outputDataFile << " ";
    }
    outputDataFile << "|" << endl;
	outputDataFile << "+-------------------------------+------------------------------------+" << endl;
	outputDataFile << "|    Electronegativity          |    " << electroNegativity;
	for(int i = 0 ; i < (32 - electroNegativity.length()) ; i++){
        outputDataFile << " ";
    }
    outputDataFile << "|" << endl;
	outputDataFile << "+-------------------------------+------------------------------------+" << endl;
	outputDataFile << "|    Electronic Configuration   |    " << electronicConfiguration;
	for(int i = 0 ; i < (32 - electronicConfiguration.length()) ; i++){
        outputDataFile << " ";
    }
    outputDataFile << "|" << endl;
	outputDataFile << "+-------------------------------+------------------------------------+" << endl;
	outputDataFile << "|    Element Symbol             |    " << elementSymbol;
	for(int i = 0 ; i < (32 - elementSymbol.length()) ; i++){
        outputDataFile << " ";
    }
    outputDataFile << "|" << endl;
	outputDataFile << "+-------------------------------+------------------------------------+" << endl;
	outputDataFile << "|    Group                      |    " << group;
	for(int i = 0 ; i < (32 - group.length()) ; i++){
        outputDataFile << " ";
    }
    outputDataFile << "|" << endl;
	outputDataFile << "+-------------------------------+------------------------------------+" << endl;
	outputDataFile << "|    Melting Point              |    " << meltingPoint;
	for(int i = 0 ; i < (32 - meltingPoint.length()) ; i++){
        outputDataFile << " ";
    }
    outputDataFile << "|" << endl;
	outputDataFile << "+-------------------------------+------------------------------------+" << endl;
	outputDataFile << "|           Modern Periodic Table - A Project By HyphenSaad          |" << endl;
	outputDataFile << "|                Saad Mansoor - 70075954 - BSCS-I / C1               |" << endl;
	outputDataFile << "+--------------------------------------------------------------------+" << endl;

    ////////////////////////////////////////////////////////////////////////////////////////////
    // result output - module
    int width = 0;

    // to calculate result window width
    if(electronicConfiguration.length() < 31 && electronicConfiguration.length() > 20){
        width = electronicConfiguration.length() * 8;
    } else if(electronicConfiguration.length() < 21 && electronicConfiguration.length() > 10){
        width = electronicConfiguration.length() * 11;
    } else if(electronicConfiguration.length() < 11 && electronicConfiguration.length() > 5){
        width = electronicConfiguration.length() * 16;
    } else {
        width = electronicConfiguration.length() * 27;
    }

    // to draw result window
    initwindow(400 + width, 325, "Result - Periodic Table");
    cout << "> Press x To Terminate The Result Screen..." << endl;

    // for background drawing
    int points[] = {0, 0, 750, 0, 750, 400, 0, 400};
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    fillpoly(4, points);

    // for table heading
    setcolor(DARKGRAY);
    setbkcolor(LIGHTGRAY);
    settextstyle(10, 0, 4);
    outtextxy((getmaxx() - (elementName.length() * 22))/2 , 8, &elementName[0]);

    // for table data
    settextstyle(11, 0, 1);
    const int bgColor_1 = DARKGRAY, fgColor_1 = LIGHTGRAY;
    const int bgColor_2 = LIGHTGRAY, fgColor_2 = DARKGRAY;

    bgLineDrawer(bgColor_1, fgColor_1, 1);
    outtextxy(50, 50, "Atomic Number");
    outtextxy(400, 50, &atomicNumber[0]);

    bgLineDrawer(bgColor_2, fgColor_2, 2);
    outtextxy(50, 70, "Atomic Radius");
    outtextxy(400, 70, &atomicRadius[0]);

    bgLineDrawer(bgColor_1, fgColor_1, 3);
    outtextxy(50, 90, "Atomic Weight");
    outtextxy(400, 90, &atomicWeight[0]);

    bgLineDrawer(bgColor_2, fgColor_2, 4);
    outtextxy(50, 110, "Block");
    outtextxy(400, 110, &block[0]);

    bgLineDrawer(bgColor_1, fgColor_1, 5);
    outtextxy(50, 130, "Boiling Point");
    outtextxy(400, 130, &boilingPoint[0]);

    bgLineDrawer(bgColor_2, fgColor_2, 6);
    outtextxy(50, 150, "Density");
    outtextxy(400, 150, &density[0]);

    bgLineDrawer(bgColor_1, fgColor_1, 7);
    outtextxy(50, 170, "Electro Negativity");
    outtextxy(400, 170, &electroNegativity[0]);

    bgLineDrawer(bgColor_2, fgColor_2, 8);
    outtextxy(50, 190, "Electronic Configuration");
    outtextxy(400, 190, &electronicConfiguration[0]);

    bgLineDrawer(bgColor_1, fgColor_1, 9);
    outtextxy(50, 210, "Element Symbol");
    outtextxy(400, 210, &elementSymbol[0]);

    bgLineDrawer(bgColor_2, fgColor_2, 10);
    outtextxy(50, 230, "Group");
    outtextxy(400, 230, &group[0]);

    bgLineDrawer(bgColor_1, fgColor_1, 11);
    outtextxy(50, 250, "Melting Point");
    outtextxy(400, 250, &meltingPoint[0]);

    // to terminate result screen
    KILL: char kill = getch();
    if(kill == 88 || kill == 120){
        closegraph(CURRENT_WINDOW);
    } else {
        goto KILL;
    }

    // to terminate the program
    B:
    cout << "> Do yo want to exit? (Y/N)\t";
    cin >> option;
    if(option == 'N' || option == 'n'){
        goto RERUN;
    } else if(option == 'Y' || option == 'y'){
        exit(1);
    } else {
        cout << "> Invalid! Command..." << endl;
        goto B;
    }
}
