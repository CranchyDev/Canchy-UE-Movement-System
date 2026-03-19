# Canchy-UE-Movement-System
Cranchy UE (Unreal Engine) Movement System, is a simplistic and quick way of introducing movement through a 'Copy &amp; Paste' fashion, making it ideal for any new projects that are being built from scratch.

<h2>Instructions to help you setup the code in your project</h2>


----------

<b>Before you proceed with copy pasting the code, make sure to create a Project that is C++.

The name of the Project CAN be different but be aware that some of the code must be adapted to that.

Don't forget to change names where needed.</b>

----------

Download the <b>Public and Private</b> folders from this repository.

Locate your recently created project, typically within <b>Documents/Unreal Projects</b>.

Open the folder and locate <b>Source/NameOfTheProject</b>.

Copy the previously downloaded <b>Public and Private</b> folders and paste <b>here (NameOfTheProject/Source/NameofOfTheProject).</b>


Then go back to the initial folder mentioned previously and locate a file that is named <b>NameOfTheProject</b> (it has an Unreal Engine symbol).

<img width="609" height="29" alt="image" src="https://github.com/user-attachments/assets/2b1b6177-9e49-4ce7-9611-cf7116f3c471" />


Right click that file and tap <b>Generate Visual Studio Project Files</b>.

<img width="297" height="92" alt="image" src="https://github.com/user-attachments/assets/cb452289-05c6-48e9-a861-a201bd075ee0" />


Afterwards, open the file <b>NameOfTheProject.sln</b> that is in the first folder of your project <b>(Documents/Unreal Projects/NameOfTheProject).</b>

<img width="606" height="23" alt="image" src="https://github.com/user-attachments/assets/bbbfa7e4-cb7a-4d74-89c5-f4010e8fba92" />

Then change the name of the _API on each of the <b>.h classes</b> within the <b>Public</b> folder (this is mandatory and your code won't work if you don't do this).

<img width="344" height="349" alt="image" src="https://github.com/user-attachments/assets/018ab303-8504-4ad4-b08e-b55e7a5260a6" />

<b>This:</b>

<img width="476" height="20" alt="image" src="https://github.com/user-attachments/assets/7a67949f-4b7b-4edc-b101-ad9bc3de463c" />

<b>To this:</b>

<img width="457" height="20" alt="image" src="https://github.com/user-attachments/assets/419b78b3-14bb-43cb-8f5c-02ebffac3248" />

Save each one of them and <b>compile the project</b>. If it goes through, we're done with this part and can move on.

If not, then go back from the beginning (or create a totally new project) and try again.

>> NOTE: Let me know if there are any further complications <b>pretty please</b>, so that I can fix them ASAP.
 
----------

<h3><b>Next, open the project within the Editor and create these Blueprint Classes:</b></h3>

<b>Open Content Drawer (or press CTRL + SPACE) and Right Click on an empty space and a menu will pop.</b>

*Down left corner of the editor*

<img width="526" height="150" alt="image" src="https://github.com/user-attachments/assets/e7003563-bd20-4fb7-a0ae-bc5ac78e291a" />

<br>

<img width="448" height="832" alt="image" src="https://github.com/user-attachments/assets/c5d5e17e-edaf-4980-8500-841ce90ef558" />

<b>IA_CameraRotation</b> (Axis2D(Vector2D))

<img width="867" height="573" alt="image" src="https://github.com/user-attachments/assets/59a166e3-31e1-4638-9eec-d313dc4899f2" />

<b>IA_Crouch</b> (Bool)

<img width="854" height="568" alt="image" src="https://github.com/user-attachments/assets/d8bc72c8-312c-4f71-bf52-b11ad1425461" />

<b>IA_Jump</b> (Bool)

<img width="856" height="576" alt="image" src="https://github.com/user-attachments/assets/05725daf-241a-424e-82e3-a4c5023127f6" />

<b>IA_Move</b> (Axis2D(Vector2D))

<img width="858" height="581" alt="image" src="https://github.com/user-attachments/assets/8935c56c-deae-4bf2-a6bd-928305781e05" />

<b>IA_Sprint</b> (Bool)

<img width="856" height="577" alt="image" src="https://github.com/user-attachments/assets/ec85c1c0-a457-4c7b-b387-bf0aa76ee862" />

<br>

-----------

<b>Then continue creating the following Blueprint Classes:</b>

<b>MainInputMappingContext</b> <- IMC (Input Mapping Context) (we'll also use this one later to setup peripheral inputs)

<img width="439" height="830" alt="image" src="https://github.com/user-attachments/assets/54f37238-1150-4ec7-8705-97bc4877b74e" />

<b>UserInterfaceInputMappingContext</b> <- Another IMC but to be used for UI for later usage <b>(highly optional)</b>

-----------

<b> Still within the editor, locate the C++ Classes folder</b>

<img width="1005" height="214" alt="image" src="https://github.com/user-attachments/assets/551de930-2f21-49c2-b18b-942bf6257c7a" />

<b>If you can't see it, then click on the wheel at the right corner of the content drawer and tick the C++ Classes checkbox.</b>

<img width="251" height="57" alt="image" src="https://github.com/user-attachments/assets/6799895d-2079-4fe8-9155-285ce991f5a5" />

<br>

<img width="211" height="779" alt="image" src="https://github.com/user-attachments/assets/97f5939f-15f6-41c3-8358-8ebd639d55ac" />

-----------

<b>Then create the follow <b>Blueprint</b> classes derived from the C++ ones:</b>

<b>MyMainCharBP</b> <- This MUST be derived from the MainChar.cpp class

<img width="391" height="495" alt="image" src="https://github.com/user-attachments/assets/2f58725e-f2c2-4b7c-aaf8-2b17bf1b6c8c" />

<b>MyMainPControllerBP</b> <- This MUST be derived from the MainPController.cpp class

<img width="418" height="505" alt="image" src="https://github.com/user-attachments/assets/c6a171bf-2455-49ad-abe9-2c883712c69b" />

>> NOTE: A Blueprint interface from the previously created class (specifically <b>PController_MainChar_Interface</b>) is not needed here, because this is a C++ ONLY interface.

-----------

<h3><b>Make sure you do these:</b></h3>

-> Within MyMainPControllerBP <- <b>You must select two IMC's for each one of the slots, and also for each IA (Input Action).</b>

<img width="1343" height="749" alt="image" src="https://github.com/user-attachments/assets/a62bd9a4-fe18-4555-9ef0-c21154e174b7" />

-> Within MainInputMapping Context <- <b>Perform this setup on the IA_Move:</b>

-> <b>S(Walking Backwards)</b>  -> Add Modifiers -> Negate
<br>
-> <b>A (Walking Left</b> ) -> Add Modifiers -> Swizzle Input Axis Values and Negate
<br>
-> <b>D (Walking Right)</b>  -> Add Modifiers -> Swizzle Input Axis Values

-> Lastly, still within MainInputMapping Context <- <b>Perform this quick setup on the IA_CameraRotation -> Modifiers -> Negate</b>

>>NOTE: When you add Negate, it automatically checks the XYZ. Make sure only Y is checked.

<img width="1287" height="1047" alt="image" src="https://github.com/user-attachments/assets/1b50d165-b780-412a-a49d-8b3eb4e65c5c" />

-> <b>Check names if something isn't working!</b> 

-> <b>On MyMainCharBP <- Change 'Use Pawn Control Rotation' to True</b>, if it isn't already. Otherwise, your camera won't turn up and down.

>>
-----------
