/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2014-2016 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    refineImmersedBoundaryMesh

Description
    Refine immersed boundary mesh for a thick plate simulation

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "refineImmersedBoundaryMesh.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    #include "addOverwriteOption.H"

    #include "setRootCase.H"

    #include "createTime.H"
    #include "createMesh.H"

    const bool overwrite = args.optionFound("overwrite");

    // 1
    {
        labelHashSet refCellSet;

        const vectorField& C = mesh.cellCentres();

        scalar L = 5;
        forAll(C, cellI)
        {
            if (mag(C[cellI].x()) <= L)
            {
                if (mag(C[cellI].y()) <= L)
                {
                    refCellSet.insert(cellI);
                }
            }
        }

        labelList refCells(refCellSet.toc());

        refineImmersedBoundaryMesh rib(mesh);
        rib.refineMesh(refCells);
    }

    // 2
    {
        labelHashSet refCellSet;

        const vectorField& C = mesh.cellCentres();

        scalar L = 3.5;
        forAll(C, cellI)
        {
            if (mag(C[cellI].x()) <= L)
            {
                if (mag(C[cellI].y()) <= L)
                {
                    refCellSet.insert(cellI);
                }
            }
        }

        labelList refCells(refCellSet.toc());

        refineImmersedBoundaryMesh rib(mesh);
        rib.refineMesh(refCells);
    }

    // 3
    {
        labelHashSet refCellSet;

        const vectorField& C = mesh.cellCentres();

        scalar L = 2.5;
        forAll(C, cellI)
        {
            if (mag(C[cellI].x()) <= L)
            {
                if (mag(C[cellI].y()) <= L)
                {
                    refCellSet.insert(cellI);
                }
            }
        }

        labelList refCells(refCellSet.toc());

        refineImmersedBoundaryMesh rib(mesh);
        rib.refineMesh(refCells);
    }

    // 4
    {
        labelHashSet refCellSet;

        const vectorField& C = mesh.cellCentres();

        scalar L = 1.5;
        forAll(C, cellI)
        {
            if (mag(C[cellI].x()) <= L)
            {
                if (mag(C[cellI].y()) <= L)
                {
                    refCellSet.insert(cellI);
                }
            }
        }

        labelList refCells(refCellSet.toc());

        refineImmersedBoundaryMesh rib(mesh);
        rib.refineMesh(refCells);
    }

    if (overwrite)
    {
        mesh.setInstance("constant");
    }

    mesh.write();

    Info<< "End\n" << endl;

    return(0);
}


// ************************************************************************* //
